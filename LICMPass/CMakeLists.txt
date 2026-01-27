add_llvm_library( LLVMLICMPass MODULE BUILDTREE_ONLY
  LICMPass.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )
