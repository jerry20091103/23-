// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Version: 2022.1
// Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module sw_compute_sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        acc_address0,
        acc_ce0,
        acc_we0,
        acc_d0,
        acc_q0,
        acc_address1,
        acc_ce1,
        acc_q1,
        w_address0,
        w_ce0,
        w_q0,
        grp_fu_157_p_din0,
        grp_fu_157_p_din1,
        grp_fu_157_p_dout0,
        grp_fu_157_p_ce
);

parameter    ap_ST_fsm_pp0_stage0 = 3'd1;
parameter    ap_ST_fsm_pp0_stage1 = 3'd2;
parameter    ap_ST_fsm_pp0_stage2 = 3'd4;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [6:0] acc_address0;
output   acc_ce0;
output   acc_we0;
output  [31:0] acc_d0;
input  [31:0] acc_q0;
output  [6:0] acc_address1;
output   acc_ce1;
input  [31:0] acc_q1;
output  [5:0] w_address0;
output   w_ce0;
input  [10:0] w_q0;
output  [31:0] grp_fu_157_p_din0;
output  [10:0] grp_fu_157_p_din1;
input  [31:0] grp_fu_157_p_dout0;
output   grp_fu_157_p_ce;

reg ap_idle;
reg[6:0] acc_address0;
reg acc_ce0;
reg acc_we0;
reg acc_ce1;
reg w_ce0;

(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
reg    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_idle_pp0;
wire    ap_CS_fsm_pp0_stage2;
wire    ap_block_state3_pp0_stage2_iter0;
wire    ap_block_state6_pp0_stage2_iter1;
wire    ap_block_pp0_stage2_subdone;
reg   [0:0] icmp_ln79_reg_607;
reg    ap_condition_exit_pp0_iter0_stage2;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state4_pp0_stage0_iter1;
wire    ap_block_pp0_stage0_11001;
reg   [3:0] j_1_reg_592;
reg   [3:0] i_reg_597;
wire   [2:0] empty_fu_176_p1;
reg   [2:0] empty_reg_602;
wire   [0:0] icmp_ln79_fu_192_p2;
reg   [6:0] indvar_flatten_load_reg_611;
wire   [0:0] icmp_ln80_fu_210_p2;
reg   [0:0] icmp_ln80_reg_616;
wire   [3:0] select_ln79_fu_216_p3;
reg   [3:0] select_ln79_reg_624;
wire   [3:0] add_ln79_1_fu_224_p2;
reg   [3:0] add_ln79_1_reg_629;
wire   [2:0] empty_30_fu_230_p1;
reg   [2:0] empty_30_reg_634;
wire   [0:0] and_ln79_fu_254_p2;
reg   [0:0] and_ln79_reg_639;
wire   [3:0] add_ln80_fu_260_p2;
reg   [3:0] add_ln80_reg_645;
wire   [2:0] select_ln80_fu_272_p3;
reg   [2:0] select_ln80_reg_651;
wire   [4:0] k_cast_fu_300_p1;
reg   [4:0] k_cast_reg_656;
wire   [4:0] add_ln82_1_fu_304_p2;
reg   [4:0] add_ln82_1_reg_661;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_state2_pp0_stage1_iter0;
wire    ap_block_state5_pp0_stage1_iter1;
wire    ap_block_pp0_stage1_11001;
wire   [0:0] addr_cmp_fu_437_p2;
reg   [0:0] addr_cmp_reg_671;
reg   [6:0] acc_addr_3_reg_681;
reg   [6:0] acc_addr_3_reg_681_pp0_iter1_reg;
wire   [0:0] addr_cmp4_fu_450_p2;
reg   [0:0] addr_cmp4_reg_686;
reg   [0:0] addr_cmp4_reg_686_pp0_iter1_reg;
wire  signed [31:0] reuse_select_fu_474_p3;
reg  signed [31:0] reuse_select_reg_691;
wire    ap_block_pp0_stage2_11001;
reg   [10:0] w_load_reg_696;
reg   [31:0] acc_load_3_reg_701;
wire  signed [31:0] sext_ln82_fu_513_p1;
reg   [31:0] mul_ln82_reg_711;
reg    ap_enable_reg_pp0_iter0_reg;
wire   [63:0] zext_ln82_fu_429_p1;
wire    ap_block_pp0_stage1;
wire   [63:0] zext_ln82_1_fu_443_p1;
wire   [63:0] zext_ln80_2_fu_419_p1;
reg   [63:0] reuse_addr_reg_fu_66;
wire    ap_loop_init;
reg   [31:0] reuse_reg_fu_70;
wire   [31:0] add_ln82_2_fu_530_p2;
reg   [31:0] ap_sig_allocacmp_reuse_reg_load;
wire    ap_block_pp0_stage2;
reg   [2:0] k_fu_74;
wire   [2:0] add_ln81_fu_481_p2;
reg   [2:0] ap_sig_allocacmp_k_load;
wire    ap_block_pp0_stage0;
reg   [3:0] j_fu_78;
wire   [3:0] select_ln80_3_fu_466_p3;
reg   [3:0] ap_sig_allocacmp_j_1;
reg   [6:0] indvar_flatten_fu_82;
wire   [6:0] select_ln80_4_fu_491_p3;
reg   [6:0] ap_sig_allocacmp_indvar_flatten_load;
reg   [3:0] i_1_fu_86;
wire   [3:0] select_ln79_1_fu_343_p3;
reg   [3:0] ap_sig_allocacmp_i;
reg   [8:0] indvar_flatten37_fu_90;
wire   [8:0] add_ln79_fu_198_p2;
reg   [8:0] ap_sig_allocacmp_indvar_flatten37_load;
wire   [2:0] empty_27_fu_180_p1;
wire   [4:0] tmp_3_fu_184_p3;
wire   [0:0] icmp_ln81_fu_248_p2;
wire   [0:0] xor_ln79_fu_242_p2;
wire   [0:0] or_ln80_fu_266_p2;
wire   [2:0] empty_31_fu_280_p1;
wire   [4:0] p_mid1_fu_284_p3;
wire   [4:0] select_ln79_3_fu_234_p3;
wire   [4:0] select_ln80_1_fu_292_p3;
wire   [5:0] tmp_1_fu_315_p3;
wire   [5:0] tmp_cast_cast_fu_326_p3;
wire   [6:0] tmp_cast_cast_cast_fu_333_p1;
wire   [6:0] zext_ln80_fu_322_p1;
wire   [2:0] trunc_ln79_fu_348_p1;
wire   [5:0] p_mid3_fu_360_p3;
wire   [5:0] select_ln79_2_fu_371_p3;
wire   [6:0] zext_ln80_1_fu_367_p1;
wire   [6:0] p_mid131_fu_382_p2;
wire   [6:0] empty_28_fu_337_p2;
wire   [5:0] tmp_cast_mid1_cast_fu_395_p3;
wire   [6:0] tmp_cast_mid1_cast_cast_fu_402_p1;
wire   [6:0] zext_ln80_3_fu_378_p1;
wire   [6:0] p_mid16_fu_406_p2;
wire   [6:0] select_ln79_4_fu_388_p3;
wire   [6:0] select_ln80_2_fu_412_p3;
wire   [4:0] p_mid_fu_352_p3;
wire   [4:0] add_ln82_fu_424_p2;
wire   [6:0] add_ln80_1_fu_486_p2;
wire   [31:0] reuse_select5_fu_524_p3;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg   [2:0] ap_NS_fsm;
wire    ap_block_pp0_stage0_subdone;
reg    ap_idle_pp0_1to1;
wire    ap_block_pp0_stage1_subdone;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter0_reg = 1'b0;
#0 ap_done_reg = 1'b0;
end

sw_compute_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage2),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((ap_loop_exit_ready == 1'b1) & (1'b0 == ap_block_pp0_stage2_subdone) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
            ap_enable_reg_pp0_iter0_reg <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter0_stage2)) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage2_subdone) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        i_1_fu_86 <= 4'd0;
    end else if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        i_1_fu_86 <= select_ln79_1_fu_343_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        if (((icmp_ln79_fu_192_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
            indvar_flatten37_fu_90 <= add_ln79_fu_198_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            indvar_flatten37_fu_90 <= 9'd0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        indvar_flatten_fu_82 <= 7'd0;
    end else if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        indvar_flatten_fu_82 <= select_ln80_4_fu_491_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        j_fu_78 <= 4'd0;
    end else if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        j_fu_78 <= select_ln80_3_fu_466_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        k_fu_74 <= 3'd0;
    end else if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        k_fu_74 <= add_ln81_fu_481_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        reuse_addr_reg_fu_66 <= 64'd18446744073709551615;
    end else if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        reuse_addr_reg_fu_66 <= zext_ln80_2_fu_419_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        reuse_reg_fu_70 <= 32'd0;
    end else if (((1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        reuse_reg_fu_70 <= add_ln82_2_fu_530_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        acc_addr_3_reg_681 <= zext_ln80_2_fu_419_p1;
        addr_cmp4_reg_686 <= addr_cmp4_fu_450_p2;
        addr_cmp_reg_671 <= addr_cmp_fu_437_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        acc_addr_3_reg_681_pp0_iter1_reg <= acc_addr_3_reg_681;
        addr_cmp4_reg_686_pp0_iter1_reg <= addr_cmp4_reg_686;
        mul_ln82_reg_711 <= grp_fu_157_p_dout0;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        acc_load_3_reg_701 <= acc_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln79_fu_192_p2 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        add_ln79_1_reg_629 <= add_ln79_1_fu_224_p2;
        add_ln80_reg_645 <= add_ln80_fu_260_p2;
        add_ln82_1_reg_661 <= add_ln82_1_fu_304_p2;
        and_ln79_reg_639 <= and_ln79_fu_254_p2;
        empty_30_reg_634 <= empty_30_fu_230_p1;
        icmp_ln80_reg_616 <= icmp_ln80_fu_210_p2;
        indvar_flatten_load_reg_611 <= ap_sig_allocacmp_indvar_flatten_load;
        k_cast_reg_656[2 : 0] <= k_cast_fu_300_p1[2 : 0];
        select_ln79_reg_624 <= select_ln79_fu_216_p3;
        select_ln80_reg_651 <= select_ln80_fu_272_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        empty_reg_602 <= empty_fu_176_p1;
        i_reg_597 <= ap_sig_allocacmp_i;
        icmp_ln79_reg_607 <= icmp_ln79_fu_192_p2;
        j_1_reg_592 <= ap_sig_allocacmp_j_1;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln79_reg_607 == 1'd0) & (1'b0 == ap_block_pp0_stage2_11001) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        reuse_select_reg_691 <= reuse_select_fu_474_p3;
        w_load_reg_696 <= w_q0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage2) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        acc_address0 = acc_addr_3_reg_681_pp0_iter1_reg;
    end else if (((1'b0 == ap_block_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        acc_address0 = zext_ln80_2_fu_419_p1;
    end else begin
        acc_address0 = 'bx;
    end
end

always @ (*) begin
    if ((((1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2)) | ((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1)))) begin
        acc_ce0 = 1'b1;
    end else begin
        acc_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        acc_ce1 = 1'b1;
    end else begin
        acc_ce1 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage2_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        acc_we0 = 1'b1;
    end else begin
        acc_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln79_reg_607 == 1'd1) & (1'b0 == ap_block_pp0_stage2_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        ap_condition_exit_pp0_iter0_stage2 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage2 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_loop_exit_ready == 1'b1) & (1'b0 == ap_block_pp0_stage2_subdone) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_pp0_stage0)) begin
        ap_enable_reg_pp0_iter0 = ap_start_int;
    end else begin
        ap_enable_reg_pp0_iter0 = ap_enable_reg_pp0_iter0_reg;
    end
end

always @ (*) begin
    if (((ap_start_int == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if ((ap_enable_reg_pp0_iter1 == 1'b0)) begin
        ap_idle_pp0_1to1 = 1'b1;
    end else begin
        ap_idle_pp0_1to1 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage2_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_i = 4'd0;
    end else begin
        ap_sig_allocacmp_i = i_1_fu_86;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_indvar_flatten37_load = 9'd0;
    end else begin
        ap_sig_allocacmp_indvar_flatten37_load = indvar_flatten37_fu_90;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_indvar_flatten_load = 7'd0;
    end else begin
        ap_sig_allocacmp_indvar_flatten_load = indvar_flatten_fu_82;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_j_1 = 4'd0;
    end else begin
        ap_sig_allocacmp_j_1 = j_fu_78;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_k_load = 3'd0;
    end else begin
        ap_sig_allocacmp_k_load = k_fu_74;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage2) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2))) begin
        ap_sig_allocacmp_reuse_reg_load = add_ln82_2_fu_530_p2;
    end else begin
        ap_sig_allocacmp_reuse_reg_load = reuse_reg_fu_70;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        w_ce0 = 1'b1;
    end else begin
        w_ce0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_start_int == 1'b0) & (ap_idle_pp0_1to1 == 1'b1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_pp0_stage2 : begin
            if ((1'b0 == ap_block_pp0_stage2_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign acc_address1 = zext_ln82_fu_429_p1;

assign acc_d0 = (reuse_select5_fu_524_p3 + mul_ln82_reg_711);

assign add_ln79_1_fu_224_p2 = (ap_sig_allocacmp_i + 4'd1);

assign add_ln79_fu_198_p2 = (ap_sig_allocacmp_indvar_flatten37_load + 9'd1);

assign add_ln80_1_fu_486_p2 = (indvar_flatten_load_reg_611 + 7'd1);

assign add_ln80_fu_260_p2 = (select_ln79_fu_216_p3 + 4'd1);

assign add_ln81_fu_481_p2 = (select_ln80_reg_651 + 3'd1);

assign add_ln82_1_fu_304_p2 = (k_cast_fu_300_p1 + select_ln80_1_fu_292_p3);

assign add_ln82_2_fu_530_p2 = (reuse_select5_fu_524_p3 + mul_ln82_reg_711);

assign add_ln82_fu_424_p2 = (k_cast_reg_656 + p_mid_fu_352_p3);

assign addr_cmp4_fu_450_p2 = ((reuse_addr_reg_fu_66 == zext_ln80_2_fu_419_p1) ? 1'b1 : 1'b0);

assign addr_cmp_fu_437_p2 = ((reuse_addr_reg_fu_66 == zext_ln82_fu_429_p1) ? 1'b1 : 1'b0);

assign and_ln79_fu_254_p2 = (xor_ln79_fu_242_p2 & icmp_ln81_fu_248_p2);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_pp0_stage2 = ap_CS_fsm[32'd2];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_subdone = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage2_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage2_iter1 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage2;

assign empty_27_fu_180_p1 = ap_sig_allocacmp_j_1[2:0];

assign empty_28_fu_337_p2 = (tmp_cast_cast_cast_fu_333_p1 + zext_ln80_fu_322_p1);

assign empty_30_fu_230_p1 = add_ln79_1_fu_224_p2[2:0];

assign empty_31_fu_280_p1 = add_ln80_fu_260_p2[2:0];

assign empty_fu_176_p1 = ap_sig_allocacmp_i[2:0];

assign grp_fu_157_p_ce = 1'b1;

assign grp_fu_157_p_din0 = reuse_select_reg_691;

assign grp_fu_157_p_din1 = sext_ln82_fu_513_p1;

assign icmp_ln79_fu_192_p2 = ((ap_sig_allocacmp_indvar_flatten37_load == 9'd256) ? 1'b1 : 1'b0);

assign icmp_ln80_fu_210_p2 = ((ap_sig_allocacmp_indvar_flatten_load == 7'd32) ? 1'b1 : 1'b0);

assign icmp_ln81_fu_248_p2 = ((ap_sig_allocacmp_k_load == 3'd4) ? 1'b1 : 1'b0);

assign k_cast_fu_300_p1 = select_ln80_fu_272_p3;

assign or_ln80_fu_266_p2 = (icmp_ln80_fu_210_p2 | and_ln79_fu_254_p2);

assign p_mid131_fu_382_p2 = (zext_ln80_1_fu_367_p1 + 7'd32);

assign p_mid16_fu_406_p2 = (tmp_cast_mid1_cast_cast_fu_402_p1 + zext_ln80_3_fu_378_p1);

assign p_mid1_fu_284_p3 = {{empty_31_fu_280_p1}, {2'd0}};

assign p_mid3_fu_360_p3 = {{empty_30_reg_634}, {3'd0}};

assign p_mid_fu_352_p3 = {{trunc_ln79_fu_348_p1}, {2'd0}};

assign reuse_select5_fu_524_p3 = ((addr_cmp4_reg_686_pp0_iter1_reg[0:0] == 1'b1) ? reuse_reg_fu_70 : acc_load_3_reg_701);

assign reuse_select_fu_474_p3 = ((addr_cmp_reg_671[0:0] == 1'b1) ? ap_sig_allocacmp_reuse_reg_load : acc_q1);

assign select_ln79_1_fu_343_p3 = ((icmp_ln80_reg_616[0:0] == 1'b1) ? add_ln79_1_reg_629 : i_reg_597);

assign select_ln79_2_fu_371_p3 = ((icmp_ln80_reg_616[0:0] == 1'b1) ? p_mid3_fu_360_p3 : tmp_1_fu_315_p3);

assign select_ln79_3_fu_234_p3 = ((icmp_ln80_fu_210_p2[0:0] == 1'b1) ? 5'd0 : tmp_3_fu_184_p3);

assign select_ln79_4_fu_388_p3 = ((icmp_ln80_reg_616[0:0] == 1'b1) ? p_mid131_fu_382_p2 : empty_28_fu_337_p2);

assign select_ln79_fu_216_p3 = ((icmp_ln80_fu_210_p2[0:0] == 1'b1) ? 4'd0 : ap_sig_allocacmp_j_1);

assign select_ln80_1_fu_292_p3 = ((and_ln79_fu_254_p2[0:0] == 1'b1) ? p_mid1_fu_284_p3 : select_ln79_3_fu_234_p3);

assign select_ln80_2_fu_412_p3 = ((and_ln79_reg_639[0:0] == 1'b1) ? p_mid16_fu_406_p2 : select_ln79_4_fu_388_p3);

assign select_ln80_3_fu_466_p3 = ((and_ln79_reg_639[0:0] == 1'b1) ? add_ln80_reg_645 : select_ln79_reg_624);

assign select_ln80_4_fu_491_p3 = ((icmp_ln80_reg_616[0:0] == 1'b1) ? 7'd1 : add_ln80_1_fu_486_p2);

assign select_ln80_fu_272_p3 = ((or_ln80_fu_266_p2[0:0] == 1'b1) ? 3'd0 : ap_sig_allocacmp_k_load);

assign sext_ln82_fu_513_p1 = $signed(w_load_reg_696);

assign tmp_1_fu_315_p3 = {{empty_reg_602}, {3'd0}};

assign tmp_3_fu_184_p3 = {{empty_27_fu_180_p1}, {2'd0}};

assign tmp_cast_cast_cast_fu_333_p1 = tmp_cast_cast_fu_326_p3;

assign tmp_cast_cast_fu_326_p3 = {{2'd2}, {j_1_reg_592}};

assign tmp_cast_mid1_cast_cast_fu_402_p1 = tmp_cast_mid1_cast_fu_395_p3;

assign tmp_cast_mid1_cast_fu_395_p3 = {{2'd2}, {add_ln80_reg_645}};

assign trunc_ln79_fu_348_p1 = select_ln79_1_fu_343_p3[2:0];

assign w_address0 = zext_ln82_1_fu_443_p1;

assign xor_ln79_fu_242_p2 = (icmp_ln80_fu_210_p2 ^ 1'd1);

assign zext_ln80_1_fu_367_p1 = p_mid3_fu_360_p3;

assign zext_ln80_2_fu_419_p1 = select_ln80_2_fu_412_p3;

assign zext_ln80_3_fu_378_p1 = select_ln79_2_fu_371_p3;

assign zext_ln80_fu_322_p1 = tmp_1_fu_315_p3;

assign zext_ln82_1_fu_443_p1 = add_ln82_1_reg_661;

assign zext_ln82_fu_429_p1 = add_ln82_fu_424_p2;

always @ (posedge ap_clk) begin
    k_cast_reg_656[4:3] <= 2'b00;
end

endmodule //sw_compute_sw_compute_Pipeline_VITIS_LOOP_79_2_VITIS_LOOP_80_3_VITIS_LOOP_81_4
