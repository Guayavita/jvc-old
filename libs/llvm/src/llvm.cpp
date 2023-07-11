#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/IRBuilder.h>
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"

#include <llvm/Support/Host.h>
#include <memory>
#include <vector>

using namespace llvm::sys;
using namespace llvm;


namespace guajavita {
void getLLVM() {
  LLVMContext context;
  IRBuilder builder(context);
  const auto module = std::make_unique<Module>("hello_llvm", context);

  const auto func_type = FunctionType::get(builder.getVoidTy(), false);
  const auto main_func = Function::Create(func_type, Function::ExternalLinkage, "main", module.get());

  const auto entry = BasicBlock::Create(context, "entrypoint", main_func);
  builder.SetInsertPoint(entry);

  const std::vector<Type*> puts_args = { builder.getInt8Ty()->getPointerTo() };
  const ArrayRef puts_args_ref(puts_args);

  const auto puts_type = FunctionType::get(builder.getInt32Ty(), puts_args_ref, false);
  const auto puts_func = module->getOrInsertFunction("puts", puts_type);

  auto str = builder.CreateGlobalStringPtr("Hello LLVM!\n");

  builder.CreateCall(puts_func, { str });
  builder.CreateRetVoid();

  module->print(llvm::errs(), nullptr);
//  auto TargetTriple = getDefaultTargetTriple();

}
} // namespace guajavita::llvm
