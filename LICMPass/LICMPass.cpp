#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/IR/Instruction.h"
#include "MySet.h"
#include "llvm/IR/Operator.h"

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace llvm;

namespace {
    struct LICMPass : public LoopPass {
        std::vector<BasicBlock *> LoopBasicBlocks;
        Instruction* InsertBefore;
        std::unordered_map<Value*, Value*> VariableMap;
        MySet InvariantInstructions;
        std::unordered_set<Value*> UsedVariable;

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

        bool isInvariant(Value* Val) {
            if (isa<Constant>(Val))
                return true;

            if (VariableMap.find(Val) != VariableMap.end()) {
                if (UsedVariable.find(VariableMap[Val]) != UsedVariable.end())
                    return false;

                for (BasicBlock *BB : LoopBasicBlocks) {
                    for (Instruction &I : *BB) {
                        if (isa<StoreInst>(&I)) {
                            if (I.getOperand(1) == VariableMap[Val]) {
                                UsedVariable.insert(VariableMap[Val]);
                                return false;
                            }
                        }
                    }
                }
                return true;
            }

            if (isa<MulOperator, AddOperator, SubOperator, SDivOperator>(Val)) {
                auto I = dyn_cast<Instruction>(Val);
                for (auto &U : I->operands()) {
					Value *Op = U.get();

                    if (InvariantInstructions.contains(Op))
                        continue;
                    if (!isInvariant(Op))
                        return false;
                }
                return true;
            }

            return false;
        }

        void findInvariants() {
            for (BasicBlock *BB : LoopBasicBlocks) {
                for (Instruction &I : *BB) {
                    if (isInvariant(&I)) {
                        InvariantInstructions.insert(&I);
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
            findInvariants();

            return false;
        }
    };
}

char LICMPass::ID = 0;
static RegisterPass<LICMPass> X("licm-pass", "This is a LICM pass");