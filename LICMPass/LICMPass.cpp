#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct LICMPass : public FunctionPass {
        static char ID;
        LICMPass() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override {
            errs() << "Hello World!\n";
            return false;
        }
    };
}

char LICMPass::ID = 0;
static RegisterPass<LICMPass> X("licm-pass", "This is a LICM pass");