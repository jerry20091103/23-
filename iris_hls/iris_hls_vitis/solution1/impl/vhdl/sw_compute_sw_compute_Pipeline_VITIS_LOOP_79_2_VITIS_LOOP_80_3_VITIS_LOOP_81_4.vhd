-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
-- Version: 2022.1
-- Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity sw_compute_sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    acc_address0 : OUT STD_LOGIC_VECTOR (6 downto 0);
    acc_ce0 : OUT STD_LOGIC;
    acc_we0 : OUT STD_LOGIC;
    acc_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    acc_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    acc_address1 : OUT STD_LOGIC_VECTOR (6 downto 0);
    acc_ce1 : OUT STD_LOGIC;
    acc_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    w_address0 : OUT STD_LOGIC_VECTOR (5 downto 0);
    w_ce0 : OUT STD_LOGIC;
    w_q0 : IN STD_LOGIC_VECTOR (10 downto 0);
    grp_fu_157_p_din0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    grp_fu_157_p_din1 : OUT STD_LOGIC_VECTOR (10 downto 0);
    grp_fu_157_p_dout0 : IN STD_LOGIC_VECTOR (31 downto 0);
    grp_fu_157_p_ce : OUT STD_LOGIC );
end;


architecture behav of sw_compute_sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_ST_fsm_pp0_stage1 : STD_LOGIC_VECTOR (2 downto 0) := "010";
    constant ap_ST_fsm_pp0_stage2 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv64_FFFFFFFFFFFFFFFF : STD_LOGIC_VECTOR (63 downto 0) := "1111111111111111111111111111111111111111111111111111111111111111";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv7_0 : STD_LOGIC_VECTOR (6 downto 0) := "0000000";
    constant ap_const_lv9_0 : STD_LOGIC_VECTOR (8 downto 0) := "000000000";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv9_100 : STD_LOGIC_VECTOR (8 downto 0) := "100000000";
    constant ap_const_lv9_1 : STD_LOGIC_VECTOR (8 downto 0) := "000000001";
    constant ap_const_lv7_20 : STD_LOGIC_VECTOR (6 downto 0) := "0100000";
    constant ap_const_lv4_1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_const_lv5_0 : STD_LOGIC_VECTOR (4 downto 0) := "00000";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv2_2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv7_1 : STD_LOGIC_VECTOR (6 downto 0) := "0000001";

attribute shreg_extract : string;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (2 downto 0) := "001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_CS_fsm_pp0_stage2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage2 : signal is "none";
    signal ap_block_state3_pp0_stage2_iter0 : BOOLEAN;
    signal ap_block_state6_pp0_stage2_iter1 : BOOLEAN;
    signal ap_block_pp0_stage2_subdone : BOOLEAN;
    signal icmp_ln79_reg_607 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_condition_exit_pp0_iter0_stage2 : STD_LOGIC;
    signal ap_loop_exit_ready : STD_LOGIC;
    signal ap_ready_int : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state4_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal j_1_reg_592 : STD_LOGIC_VECTOR (3 downto 0);
    signal i_reg_597 : STD_LOGIC_VECTOR (3 downto 0);
    signal empty_fu_176_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal empty_reg_602 : STD_LOGIC_VECTOR (2 downto 0);
    signal icmp_ln79_fu_192_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal indvar_flatten_load_reg_611 : STD_LOGIC_VECTOR (6 downto 0);
    signal icmp_ln80_fu_210_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln80_reg_616 : STD_LOGIC_VECTOR (0 downto 0);
    signal select_ln79_fu_216_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal select_ln79_reg_624 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln79_1_fu_224_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln79_1_reg_629 : STD_LOGIC_VECTOR (3 downto 0);
    signal empty_30_fu_230_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal empty_30_reg_634 : STD_LOGIC_VECTOR (2 downto 0);
    signal and_ln79_fu_254_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln79_reg_639 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln80_fu_260_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln80_reg_645 : STD_LOGIC_VECTOR (3 downto 0);
    signal select_ln80_fu_272_p3 : STD_LOGIC_VECTOR (2 downto 0);
    signal select_ln80_reg_651 : STD_LOGIC_VECTOR (2 downto 0);
    signal k_cast_fu_300_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal k_cast_reg_656 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln82_1_fu_304_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln82_1_reg_661 : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_CS_fsm_pp0_stage1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage1 : signal is "none";
    signal ap_block_state2_pp0_stage1_iter0 : BOOLEAN;
    signal ap_block_state5_pp0_stage1_iter1 : BOOLEAN;
    signal ap_block_pp0_stage1_11001 : BOOLEAN;
    signal addr_cmp_fu_437_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal addr_cmp_reg_671 : STD_LOGIC_VECTOR (0 downto 0);
    signal acc_addr_3_reg_681 : STD_LOGIC_VECTOR (6 downto 0);
    signal acc_addr_3_reg_681_pp0_iter1_reg : STD_LOGIC_VECTOR (6 downto 0);
    signal addr_cmp4_fu_450_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal addr_cmp4_reg_686 : STD_LOGIC_VECTOR (0 downto 0);
    signal addr_cmp4_reg_686_pp0_iter1_reg : STD_LOGIC_VECTOR (0 downto 0);
    signal reuse_select_fu_474_p3 : STD_LOGIC_VECTOR (31 downto 0);
    signal reuse_select_reg_691 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_block_pp0_stage2_11001 : BOOLEAN;
    signal w_load_reg_696 : STD_LOGIC_VECTOR (10 downto 0);
    signal acc_load_3_reg_701 : STD_LOGIC_VECTOR (31 downto 0);
    signal sext_ln82_fu_513_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal mul_ln82_reg_711 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_enable_reg_pp0_iter0_reg : STD_LOGIC := '0';
    signal zext_ln82_fu_429_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage1 : BOOLEAN;
    signal zext_ln82_1_fu_443_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln80_2_fu_419_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal reuse_addr_reg_fu_66 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_loop_init : STD_LOGIC;
    signal reuse_reg_fu_70 : STD_LOGIC_VECTOR (31 downto 0);
    signal add_ln82_2_fu_530_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_sig_allocacmp_reuse_reg_load : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_block_pp0_stage2 : BOOLEAN;
    signal k_fu_74 : STD_LOGIC_VECTOR (2 downto 0);
    signal add_ln81_fu_481_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_sig_allocacmp_k_load : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal j_fu_78 : STD_LOGIC_VECTOR (3 downto 0);
    signal select_ln80_3_fu_466_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_sig_allocacmp_j_1 : STD_LOGIC_VECTOR (3 downto 0);
    signal indvar_flatten_fu_82 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln80_4_fu_491_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal ap_sig_allocacmp_indvar_flatten_load : STD_LOGIC_VECTOR (6 downto 0);
    signal i_1_fu_86 : STD_LOGIC_VECTOR (3 downto 0);
    signal select_ln79_1_fu_343_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_sig_allocacmp_i : STD_LOGIC_VECTOR (3 downto 0);
    signal indvar_flatten37_fu_90 : STD_LOGIC_VECTOR (8 downto 0);
    signal add_ln79_fu_198_p2 : STD_LOGIC_VECTOR (8 downto 0);
    signal ap_sig_allocacmp_indvar_flatten37_load : STD_LOGIC_VECTOR (8 downto 0);
    signal empty_27_fu_180_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal tmp_3_fu_184_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln81_fu_248_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal xor_ln79_fu_242_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal or_ln80_fu_266_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal empty_31_fu_280_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal p_mid1_fu_284_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal select_ln79_3_fu_234_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal select_ln80_1_fu_292_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal tmp_1_fu_315_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_cast_cast_fu_326_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_cast_cast_cast_fu_333_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln80_fu_322_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal trunc_ln79_fu_348_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal p_mid3_fu_360_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal select_ln79_2_fu_371_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal zext_ln80_1_fu_367_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal p_mid131_fu_382_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal empty_28_fu_337_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal tmp_cast_mid1_cast_fu_395_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_cast_mid1_cast_cast_fu_402_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal zext_ln80_3_fu_378_p1 : STD_LOGIC_VECTOR (6 downto 0);
    signal p_mid16_fu_406_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln79_4_fu_388_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal select_ln80_2_fu_412_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal p_mid_fu_352_p3 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln82_fu_424_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln80_1_fu_486_p2 : STD_LOGIC_VECTOR (6 downto 0);
    signal reuse_select5_fu_524_p3 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_continue_int : STD_LOGIC;
    signal ap_done_int : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal ap_idle_pp0_1to1 : STD_LOGIC;
    signal ap_block_pp0_stage1_subdone : BOOLEAN;
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_start_int : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component sw_compute_mul_32s_11s_32_2_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (10 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component sw_compute_flow_control_loop_pipe_sequential_init IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_start_int : OUT STD_LOGIC;
        ap_loop_init : OUT STD_LOGIC;
        ap_ready_int : IN STD_LOGIC;
        ap_loop_exit_ready : IN STD_LOGIC;
        ap_loop_exit_done : IN STD_LOGIC;
        ap_continue_int : OUT STD_LOGIC;
        ap_done_int : IN STD_LOGIC );
    end component;



begin
    flow_control_loop_pipe_sequential_init_U : component sw_compute_flow_control_loop_pipe_sequential_init
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => ap_start,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_start_int => ap_start_int,
        ap_loop_init => ap_loop_init,
        ap_ready_int => ap_ready_int,
        ap_loop_exit_ready => ap_condition_exit_pp0_iter0_stage2,
        ap_loop_exit_done => ap_done_int,
        ap_continue_int => ap_continue_int,
        ap_done_int => ap_done_int);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue_int = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage2_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter0_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter0_reg <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) then 
                    ap_enable_reg_pp0_iter0_reg <= ap_start_int;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_condition_exit_pp0_iter0_stage2)) then 
                    ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage2_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                    ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
                end if; 
            end if;
        end if;
    end process;


    i_1_fu_86_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                i_1_fu_86 <= ap_const_lv4_0;
            elsif (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then 
                i_1_fu_86 <= select_ln79_1_fu_343_p3;
            end if; 
        end if;
    end process;

    indvar_flatten37_fu_90_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                if (((icmp_ln79_fu_192_p2 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                    indvar_flatten37_fu_90 <= add_ln79_fu_198_p2;
                elsif ((ap_loop_init = ap_const_logic_1)) then 
                    indvar_flatten37_fu_90 <= ap_const_lv9_0;
                end if;
            end if; 
        end if;
    end process;

    indvar_flatten_fu_82_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                indvar_flatten_fu_82 <= ap_const_lv7_0;
            elsif (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                indvar_flatten_fu_82 <= select_ln80_4_fu_491_p3;
            end if; 
        end if;
    end process;

    j_fu_78_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                j_fu_78 <= ap_const_lv4_0;
            elsif (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                j_fu_78 <= select_ln80_3_fu_466_p3;
            end if; 
        end if;
    end process;

    k_fu_74_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                k_fu_74 <= ap_const_lv3_0;
            elsif (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                k_fu_74 <= add_ln81_fu_481_p2;
            end if; 
        end if;
    end process;

    reuse_addr_reg_fu_66_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                reuse_addr_reg_fu_66 <= ap_const_lv64_FFFFFFFFFFFFFFFF;
            elsif (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then 
                reuse_addr_reg_fu_66 <= zext_ln80_2_fu_419_p1;
            end if; 
        end if;
    end process;

    reuse_reg_fu_70_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                reuse_reg_fu_70 <= ap_const_lv32_0;
            elsif (((ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
                reuse_reg_fu_70 <= add_ln82_2_fu_530_p2;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then
                acc_addr_3_reg_681 <= zext_ln80_2_fu_419_p1(7 - 1 downto 0);
                addr_cmp4_reg_686 <= addr_cmp4_fu_450_p2;
                addr_cmp_reg_671 <= addr_cmp_fu_437_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then
                acc_addr_3_reg_681_pp0_iter1_reg <= acc_addr_3_reg_681;
                addr_cmp4_reg_686_pp0_iter1_reg <= addr_cmp4_reg_686;
                mul_ln82_reg_711 <= grp_fu_157_p_dout0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then
                acc_load_3_reg_701 <= acc_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln79_fu_192_p2 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                add_ln79_1_reg_629 <= add_ln79_1_fu_224_p2;
                add_ln80_reg_645 <= add_ln80_fu_260_p2;
                add_ln82_1_reg_661 <= add_ln82_1_fu_304_p2;
                and_ln79_reg_639 <= and_ln79_fu_254_p2;
                empty_30_reg_634 <= empty_30_fu_230_p1;
                icmp_ln80_reg_616 <= icmp_ln80_fu_210_p2;
                indvar_flatten_load_reg_611 <= ap_sig_allocacmp_indvar_flatten_load;
                    k_cast_reg_656(2 downto 0) <= k_cast_fu_300_p1(2 downto 0);
                select_ln79_reg_624 <= select_ln79_fu_216_p3;
                select_ln80_reg_651 <= select_ln80_fu_272_p3;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                empty_reg_602 <= empty_fu_176_p1;
                i_reg_597 <= ap_sig_allocacmp_i;
                icmp_ln79_reg_607 <= icmp_ln79_fu_192_p2;
                j_1_reg_592 <= ap_sig_allocacmp_j_1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln79_reg_607 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then
                reuse_select_reg_691 <= reuse_select_fu_474_p3;
                w_load_reg_696 <= w_q0;
            end if;
        end if;
    end process;
    k_cast_reg_656(4 downto 3) <= "00";

    ap_NS_fsm_assign_proc : process (ap_CS_fsm, ap_block_pp0_stage2_subdone, ap_block_pp0_stage0_subdone, ap_idle_pp0_1to1, ap_block_pp0_stage1_subdone, ap_start_int)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_pp0_stage0 => 
                if ((not(((ap_start_int = ap_const_logic_0) and (ap_idle_pp0_1to1 = ap_const_logic_1))) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage1;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                end if;
            when ap_ST_fsm_pp0_stage1 => 
                if ((ap_const_boolean_0 = ap_block_pp0_stage1_subdone)) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage2;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage1;
                end if;
            when ap_ST_fsm_pp0_stage2 => 
                if ((ap_const_boolean_0 = ap_block_pp0_stage2_subdone)) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage2;
                end if;
            when others =>  
                ap_NS_fsm <= "XXX";
        end case;
    end process;

    acc_address0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_CS_fsm_pp0_stage2, ap_CS_fsm_pp0_stage1, acc_addr_3_reg_681_pp0_iter1_reg, ap_block_pp0_stage1, zext_ln80_2_fu_419_p1, ap_block_pp0_stage2)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage2) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            acc_address0 <= acc_addr_3_reg_681_pp0_iter1_reg;
        elsif (((ap_const_boolean_0 = ap_block_pp0_stage1) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then 
            acc_address0 <= zext_ln80_2_fu_419_p1(7 - 1 downto 0);
        else 
            acc_address0 <= "XXXXXXX";
        end if; 
    end process;

    acc_address1 <= zext_ln82_fu_429_p1(7 - 1 downto 0);

    acc_ce0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_CS_fsm_pp0_stage2, ap_CS_fsm_pp0_stage1, ap_block_pp0_stage1_11001, ap_block_pp0_stage2_11001)
    begin
        if ((((ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2)) or ((ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1)))) then 
            acc_ce0 <= ap_const_logic_1;
        else 
            acc_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    acc_ce1_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage1, ap_block_pp0_stage1_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then 
            acc_ce1 <= ap_const_logic_1;
        else 
            acc_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    acc_d0 <= std_logic_vector(unsigned(reuse_select5_fu_524_p3) + unsigned(mul_ln82_reg_711));

    acc_we0_assign_proc : process(ap_enable_reg_pp0_iter1, ap_CS_fsm_pp0_stage2, ap_block_pp0_stage2_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage2_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            acc_we0 <= ap_const_logic_1;
        else 
            acc_we0 <= ap_const_logic_0;
        end if; 
    end process;

    add_ln79_1_fu_224_p2 <= std_logic_vector(unsigned(ap_sig_allocacmp_i) + unsigned(ap_const_lv4_1));
    add_ln79_fu_198_p2 <= std_logic_vector(unsigned(ap_sig_allocacmp_indvar_flatten37_load) + unsigned(ap_const_lv9_1));
    add_ln80_1_fu_486_p2 <= std_logic_vector(unsigned(indvar_flatten_load_reg_611) + unsigned(ap_const_lv7_1));
    add_ln80_fu_260_p2 <= std_logic_vector(unsigned(select_ln79_fu_216_p3) + unsigned(ap_const_lv4_1));
    add_ln81_fu_481_p2 <= std_logic_vector(unsigned(select_ln80_reg_651) + unsigned(ap_const_lv3_1));
    add_ln82_1_fu_304_p2 <= std_logic_vector(unsigned(k_cast_fu_300_p1) + unsigned(select_ln80_1_fu_292_p3));
    add_ln82_2_fu_530_p2 <= std_logic_vector(unsigned(reuse_select5_fu_524_p3) + unsigned(mul_ln82_reg_711));
    add_ln82_fu_424_p2 <= std_logic_vector(unsigned(k_cast_reg_656) + unsigned(p_mid_fu_352_p3));
    addr_cmp4_fu_450_p2 <= "1" when (reuse_addr_reg_fu_66 = zext_ln80_2_fu_419_p1) else "0";
    addr_cmp_fu_437_p2 <= "1" when (reuse_addr_reg_fu_66 = zext_ln82_fu_429_p1) else "0";
    and_ln79_fu_254_p2 <= (xor_ln79_fu_242_p2 and icmp_ln81_fu_248_p2);
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(0);
    ap_CS_fsm_pp0_stage1 <= ap_CS_fsm(1);
    ap_CS_fsm_pp0_stage2 <= ap_CS_fsm(2);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage2 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage2_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage2_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage1_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state3_pp0_stage2_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state4_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state5_pp0_stage1_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state6_pp0_stage2_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_exit_pp0_iter0_stage2_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage2, ap_block_pp0_stage2_subdone, icmp_ln79_reg_607)
    begin
        if (((icmp_ln79_reg_607 = ap_const_lv1_1) and (ap_const_boolean_0 = ap_block_pp0_stage2_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            ap_condition_exit_pp0_iter0_stage2 <= ap_const_logic_1;
        else 
            ap_condition_exit_pp0_iter0_stage2 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_int_assign_proc : process(ap_CS_fsm_pp0_stage2, ap_block_pp0_stage2_subdone, ap_loop_exit_ready, ap_done_reg)
    begin
        if (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage2_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            ap_done_int <= ap_const_logic_1;
        else 
            ap_done_int <= ap_done_reg;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);

    ap_enable_reg_pp0_iter0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0_reg, ap_start_int)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) then 
            ap_enable_reg_pp0_iter0 <= ap_start_int;
        else 
            ap_enable_reg_pp0_iter0 <= ap_enable_reg_pp0_iter0_reg;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_idle_pp0, ap_start_int)
    begin
        if (((ap_start_int = ap_const_logic_0) and (ap_idle_pp0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1)
    begin
        if (((ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_1to1_assign_proc : process(ap_enable_reg_pp0_iter1)
    begin
        if ((ap_enable_reg_pp0_iter1 = ap_const_logic_0)) then 
            ap_idle_pp0_1to1 <= ap_const_logic_1;
        else 
            ap_idle_pp0_1to1 <= ap_const_logic_0;
        end if; 
    end process;

    ap_loop_exit_ready <= ap_condition_exit_pp0_iter0_stage2;

    ap_ready_int_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage2, ap_block_pp0_stage2_subdone)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage2_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            ap_ready_int <= ap_const_logic_1;
        else 
            ap_ready_int <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_allocacmp_i_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_loop_init, ap_block_pp0_stage0, i_1_fu_86)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_i <= ap_const_lv4_0;
        else 
            ap_sig_allocacmp_i <= i_1_fu_86;
        end if; 
    end process;


    ap_sig_allocacmp_indvar_flatten37_load_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_loop_init, ap_block_pp0_stage0, indvar_flatten37_fu_90)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_indvar_flatten37_load <= ap_const_lv9_0;
        else 
            ap_sig_allocacmp_indvar_flatten37_load <= indvar_flatten37_fu_90;
        end if; 
    end process;


    ap_sig_allocacmp_indvar_flatten_load_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_loop_init, ap_block_pp0_stage0, indvar_flatten_fu_82)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_indvar_flatten_load <= ap_const_lv7_0;
        else 
            ap_sig_allocacmp_indvar_flatten_load <= indvar_flatten_fu_82;
        end if; 
    end process;


    ap_sig_allocacmp_j_1_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_loop_init, ap_block_pp0_stage0, j_fu_78)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_j_1 <= ap_const_lv4_0;
        else 
            ap_sig_allocacmp_j_1 <= j_fu_78;
        end if; 
    end process;


    ap_sig_allocacmp_k_load_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_loop_init, k_fu_74, ap_block_pp0_stage0)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_k_load <= ap_const_lv3_0;
        else 
            ap_sig_allocacmp_k_load <= k_fu_74;
        end if; 
    end process;


    ap_sig_allocacmp_reuse_reg_load_assign_proc : process(ap_enable_reg_pp0_iter1, ap_CS_fsm_pp0_stage2, reuse_reg_fu_70, add_ln82_2_fu_530_p2, ap_block_pp0_stage2)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage2) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage2))) then 
            ap_sig_allocacmp_reuse_reg_load <= add_ln82_2_fu_530_p2;
        else 
            ap_sig_allocacmp_reuse_reg_load <= reuse_reg_fu_70;
        end if; 
    end process;

    empty_27_fu_180_p1 <= ap_sig_allocacmp_j_1(3 - 1 downto 0);
    empty_28_fu_337_p2 <= std_logic_vector(unsigned(tmp_cast_cast_cast_fu_333_p1) + unsigned(zext_ln80_fu_322_p1));
    empty_30_fu_230_p1 <= add_ln79_1_fu_224_p2(3 - 1 downto 0);
    empty_31_fu_280_p1 <= add_ln80_fu_260_p2(3 - 1 downto 0);
    empty_fu_176_p1 <= ap_sig_allocacmp_i(3 - 1 downto 0);
    grp_fu_157_p_ce <= ap_const_logic_1;
    grp_fu_157_p_din0 <= reuse_select_reg_691;
    grp_fu_157_p_din1 <= sext_ln82_fu_513_p1(11 - 1 downto 0);
    icmp_ln79_fu_192_p2 <= "1" when (ap_sig_allocacmp_indvar_flatten37_load = ap_const_lv9_100) else "0";
    icmp_ln80_fu_210_p2 <= "1" when (ap_sig_allocacmp_indvar_flatten_load = ap_const_lv7_20) else "0";
    icmp_ln81_fu_248_p2 <= "1" when (ap_sig_allocacmp_k_load = ap_const_lv3_4) else "0";
    k_cast_fu_300_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln80_fu_272_p3),5));
    or_ln80_fu_266_p2 <= (icmp_ln80_fu_210_p2 or and_ln79_fu_254_p2);
    p_mid131_fu_382_p2 <= std_logic_vector(unsigned(zext_ln80_1_fu_367_p1) + unsigned(ap_const_lv7_20));
    p_mid16_fu_406_p2 <= std_logic_vector(unsigned(tmp_cast_mid1_cast_cast_fu_402_p1) + unsigned(zext_ln80_3_fu_378_p1));
    p_mid1_fu_284_p3 <= (empty_31_fu_280_p1 & ap_const_lv2_0);
    p_mid3_fu_360_p3 <= (empty_30_reg_634 & ap_const_lv3_0);
    p_mid_fu_352_p3 <= (trunc_ln79_fu_348_p1 & ap_const_lv2_0);
    reuse_select5_fu_524_p3 <= 
        reuse_reg_fu_70 when (addr_cmp4_reg_686_pp0_iter1_reg(0) = '1') else 
        acc_load_3_reg_701;
    reuse_select_fu_474_p3 <= 
        ap_sig_allocacmp_reuse_reg_load when (addr_cmp_reg_671(0) = '1') else 
        acc_q1;
    select_ln79_1_fu_343_p3 <= 
        add_ln79_1_reg_629 when (icmp_ln80_reg_616(0) = '1') else 
        i_reg_597;
    select_ln79_2_fu_371_p3 <= 
        p_mid3_fu_360_p3 when (icmp_ln80_reg_616(0) = '1') else 
        tmp_1_fu_315_p3;
    select_ln79_3_fu_234_p3 <= 
        ap_const_lv5_0 when (icmp_ln80_fu_210_p2(0) = '1') else 
        tmp_3_fu_184_p3;
    select_ln79_4_fu_388_p3 <= 
        p_mid131_fu_382_p2 when (icmp_ln80_reg_616(0) = '1') else 
        empty_28_fu_337_p2;
    select_ln79_fu_216_p3 <= 
        ap_const_lv4_0 when (icmp_ln80_fu_210_p2(0) = '1') else 
        ap_sig_allocacmp_j_1;
    select_ln80_1_fu_292_p3 <= 
        p_mid1_fu_284_p3 when (and_ln79_fu_254_p2(0) = '1') else 
        select_ln79_3_fu_234_p3;
    select_ln80_2_fu_412_p3 <= 
        p_mid16_fu_406_p2 when (and_ln79_reg_639(0) = '1') else 
        select_ln79_4_fu_388_p3;
    select_ln80_3_fu_466_p3 <= 
        add_ln80_reg_645 when (and_ln79_reg_639(0) = '1') else 
        select_ln79_reg_624;
    select_ln80_4_fu_491_p3 <= 
        ap_const_lv7_1 when (icmp_ln80_reg_616(0) = '1') else 
        add_ln80_1_fu_486_p2;
    select_ln80_fu_272_p3 <= 
        ap_const_lv3_0 when (or_ln80_fu_266_p2(0) = '1') else 
        ap_sig_allocacmp_k_load;
        sext_ln82_fu_513_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(w_load_reg_696),32));

    tmp_1_fu_315_p3 <= (empty_reg_602 & ap_const_lv3_0);
    tmp_3_fu_184_p3 <= (empty_27_fu_180_p1 & ap_const_lv2_0);
    tmp_cast_cast_cast_fu_333_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_cast_cast_fu_326_p3),7));
    tmp_cast_cast_fu_326_p3 <= (ap_const_lv2_2 & j_1_reg_592);
    tmp_cast_mid1_cast_cast_fu_402_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_cast_mid1_cast_fu_395_p3),7));
    tmp_cast_mid1_cast_fu_395_p3 <= (ap_const_lv2_2 & add_ln80_reg_645);
    trunc_ln79_fu_348_p1 <= select_ln79_1_fu_343_p3(3 - 1 downto 0);
    w_address0 <= zext_ln82_1_fu_443_p1(6 - 1 downto 0);

    w_ce0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage1, ap_block_pp0_stage1_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1))) then 
            w_ce0 <= ap_const_logic_1;
        else 
            w_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    xor_ln79_fu_242_p2 <= (icmp_ln80_fu_210_p2 xor ap_const_lv1_1);
    zext_ln80_1_fu_367_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(p_mid3_fu_360_p3),7));
    zext_ln80_2_fu_419_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln80_2_fu_412_p3),64));
    zext_ln80_3_fu_378_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(select_ln79_2_fu_371_p3),7));
    zext_ln80_fu_322_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_1_fu_315_p3),7));
    zext_ln82_1_fu_443_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln82_1_reg_661),64));
    zext_ln82_fu_429_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln82_fu_424_p2),64));
end behav;
