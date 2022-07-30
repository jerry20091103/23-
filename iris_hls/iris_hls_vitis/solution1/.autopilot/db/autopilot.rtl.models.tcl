set SynModuleInfo {
  {SRCNAME sw_compute_Pipeline_VITIS_LOOP_75_1 MODELNAME sw_compute_Pipeline_VITIS_LOOP_75_1 RTLNAME sw_compute_sw_compute_Pipeline_VITIS_LOOP_75_1}
  {SRCNAME sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4 MODELNAME sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4 RTLNAME sw_compute_sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4
    SUBMODULES {
      {MODELNAME sw_compute_flow_control_loop_pipe_sequential_init RTLNAME sw_compute_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME sw_compute_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME sw_compute_Pipeline_VITIS_LOOP_89_5 MODELNAME sw_compute_Pipeline_VITIS_LOOP_89_5 RTLNAME sw_compute_sw_compute_Pipeline_VITIS_LOOP_89_5
    SUBMODULES {
      {MODELNAME sw_compute_mul_32s_10ns_32_2_1 RTLNAME sw_compute_mul_32s_10ns_32_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME sw_compute_Pipeline_VITIS_LOOP_98_6_VITIS_LOOP_99_7 MODELNAME sw_compute_Pipeline_VITIS_LOOP_98_6_VITIS_LOOP_99_7 RTLNAME sw_compute_sw_compute_Pipeline_VITIS_LOOP_98_6_VITIS_LOOP_99_7}
  {SRCNAME sw_compute_Pipeline_VITIS_LOOP_107_9 MODELNAME sw_compute_Pipeline_VITIS_LOOP_107_9 RTLNAME sw_compute_sw_compute_Pipeline_VITIS_LOOP_107_9}
  {SRCNAME sw_compute MODELNAME sw_compute RTLNAME sw_compute IS_TOP 1
    SUBMODULES {
      {MODELNAME sw_compute_mul_32s_11s_32_2_1 RTLNAME sw_compute_mul_32s_11s_32_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME sw_compute_w_ROM_AUTO_1R RTLNAME sw_compute_w_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME sw_compute_acc_RAM_AUTO_1R1W RTLNAME sw_compute_acc_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME sw_compute_gmem_m_axi RTLNAME sw_compute_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME sw_compute_control_s_axi RTLNAME sw_compute_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
