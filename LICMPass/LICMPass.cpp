#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/IR/Instruction.h"

#include <vector>
#include <unordered_map>

using namespace llvm;

namespace {
    struct LICMPass : public LoopPass {
        std::vector<BasicBlock *> LoopBasicBlocks;
        Instruction* InsertBefore;
        std::unordered_map<Value*, Value*> VariableMap;

        static char ID;
        LICMPass() : LoopPass(ID) {}

        void variableMapping() {
            Function *Parent = LoopBasicBlocks[0]->getParent();
            for (BasicBlock &BB: *Parent) {
                for (Instruction &I : BB) {
                    if (auto *LI = dyn_cast<LoadInst>(&I)) {
                        VariableMap[LI] = LI->getOperand(0);
                    }
                }
            }
        }

        bool runOnLoop(Loop *L, LPPassManager&) override {
            LoopBasicBlocks = L->getBlocksVector();
            BasicBlock *PreHeader = L->getLoopPreheader();
            if (!PreHeader)
                return false;
            InsertBefore = PreHeader->getTerminator();

            variableMapping();

            return false;
        }
    };
}

char LICMPass::ID = 0;
static RegisterPass<LICMPass> X("licm-pass", "This is a LICM pass");