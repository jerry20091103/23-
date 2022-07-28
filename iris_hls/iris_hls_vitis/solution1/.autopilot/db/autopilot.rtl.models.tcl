set SynModuleInfo {
  {SRCNAME iris_module MODELNAME iris_module RTLNAME iris_module IS_TOP 1
    SUBMODULES {
      {MODELNAME iris_module_gmem_m_axi RTLNAME iris_module_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME iris_module_control_s_axi RTLNAME iris_module_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
