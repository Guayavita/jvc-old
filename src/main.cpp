#include <iostream>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/IRBuilder.h>
#include <vector>
#include <memory>

#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

using llvm::LLVMContext;
using llvm::IRBuilder;
using llvm::Module;
using llvm::FunctionType;
using llvm::Function;
using llvm::BasicBlock;
using llvm::Type;
using llvm::ArrayRef;

int main(int argc, char* argv[])
{
    /**
LLVMContext context;
    IRBuilder<> builder(context);
    const auto module = std::make_unique<Module>("hello_llvm", context);

    const auto func_type = FunctionType::get(builder.getVoidTy(), false);
    const auto main_func = Function::Create(func_type, Function::ExternalLinkage, "main", module.get());

    const auto entry = BasicBlock::Create(context, "entrypoint", main_func);
    builder.SetInsertPoint(entry);

    const std::vector<Type*> puts_args = { builder.getInt8Ty()->getPointerTo() };
    const ArrayRef<Type*> puts_args_ref(puts_args);

    const auto puts_type = FunctionType::get(builder.getInt32Ty(), puts_args_ref, false);
    const auto puts_func = module->getOrInsertFunction("puts", puts_type);

    auto str = builder.CreateGlobalStringPtr("Hello LLVM!\n");

    builder.CreateCall(puts_func, { str });
    builder.CreateRetVoid();

    module->print(llvm::errs(), nullptr);
  **/
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  std::string s = "Boost C++ Libraries";
  tokenizer tok{s};
  for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
    std::cout << *it << '\n';

    return 0;
}


