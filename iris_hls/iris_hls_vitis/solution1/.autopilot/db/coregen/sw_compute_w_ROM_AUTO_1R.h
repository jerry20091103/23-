// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __sw_compute_w_ROM_AUTO_1R_H__
#define __sw_compute_w_ROM_AUTO_1R_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct sw_compute_w_ROM_AUTO_1R_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 11;
  static const unsigned AddressRange = 59;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(sw_compute_w_ROM_AUTO_1R_ram) {
        ram[0] = "0b00000011111";
        ram[1] = "0b00000101110";
        ram[2] = "0b11110011101";
        ram[3] = "0b11110100111";
        ram[4] = "0b00000011010";
        ram[5] = "0b00000010100";
        ram[6] = "0b11110100101";
        ram[7] = "0b11110101011";
        ram[8] = "0b00000111110";
        ram[9] = "0b11110000011";
        ram[10] = "0b00001111111";
        ram[11] = "0b11111100001";
        ram[12] = "0b00000111100";
        ram[13] = "0b11110100100";
        ram[14] = "0b00001110000";
        ram[15] = "0b11111101111";
        ram[16] = "0b00000011000";
        ram[17] = "0b11111011000";
        ram[18] = "0b00001100010";
        ram[19] = "0b00000001110";
        ram[20] = "0b11111111110";
        ram[21] = "0b11111110111";
        ram[22] = "0b11111010100";
        ram[23] = "0b11110111110";
        ram[24] = "0b00000000010";
        ram[25] = "0b11111101111";
        ram[26] = "0b11111001111";
        ram[27] = "0b11110111110";
        ram[28] = "0b11111111000";
        ram[29] = "0b11111110000";
        ram[30] = "0b00000000011";
        ram[31] = "0b00000001101";
        ram[32] = "0b00001010010";
        ram[33] = "0b00001000100";
        ram[34] = "0b11110000000";
        ram[35] = "0b11110000000";
        ram[36] = "0b11110000010";
        ram[37] = "0b00000100110";
        ram[38] = "0b00000100101";
        ram[39] = "0b00000000001";
        ram[40] = "0b00000011101";
        ram[41] = "0b00000100010";
        ram[42] = "0b00000000100";
        ram[43] = "0b00000000000";
        ram[44] = "0b11111101101";
        ram[45] = "0b00000011101";
        ram[46] = "0b00000100011";
        ram[47] = "0b11111111100";
        ram[48] = "0b11110110000";
        ram[49] = "0b11110111110";
        ram[50] = "0b00000001110";
        ram[51] = "0b00000010011";
        ram[52] = "0b00000011010";
        ram[53] = "0b11111010011";
        ram[54] = "0b11111010000";
        ram[55] = "0b11111111101";
        ram[56] = "0b10010110101";
        ram[57] = "0b11110100101";
        ram[58] = "0b01010001110";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(sw_compute_w_ROM_AUTO_1R) {


static const unsigned DataWidth = 11;
static const unsigned AddressRange = 59;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sw_compute_w_ROM_AUTO_1R_ram* meminst;


SC_CTOR(sw_compute_w_ROM_AUTO_1R) {
meminst = new sw_compute_w_ROM_AUTO_1R_ram("sw_compute_w_ROM_AUTO_1R_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~sw_compute_w_ROM_AUTO_1R() {
    delete meminst;
}


};//endmodule
#endif
