-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
-- Tool Version Limit: 2022.04
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity sw_compute_w_ROM_AUTO_1R is 
    generic(
             DataWidth     : integer := 11; 
             AddressWidth     : integer := 6; 
             AddressRange    : integer := 59
    ); 
    port (
          address0      : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DataWidth-1 downto 0);
          reset     : in std_logic;
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of sw_compute_w_ROM_AUTO_1R is 

signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 
type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 
signal mem : mem_array := (
    0 => "00000011111", 1 => "00000101110", 2 => "11110011101", 
    3 => "11110100111", 4 => "00000011010", 5 => "00000010100", 
    6 => "11110100101", 7 => "11110101011", 8 => "00000111110", 
    9 => "11110000011", 10 => "00001111111", 11 => "11111100001", 
    12 => "00000111100", 13 => "11110100100", 14 => "00001110000", 
    15 => "11111101111", 16 => "00000011000", 17 => "11111011000", 
    18 => "00001100010", 19 => "00000001110", 20 => "11111111110", 
    21 => "11111110111", 22 => "11111010100", 23 => "11110111110", 
    24 => "00000000010", 25 => "11111101111", 26 => "11111001111", 
    27 => "11110111110", 28 => "11111111000", 29 => "11111110000", 
    30 => "00000000011", 31 => "00000001101", 32 => "00001010010", 
    33 => "00001000100", 34 to 35=> "11110000000", 36 => "11110000010", 
    37 => "00000100110", 38 => "00000100101", 39 => "00000000001", 
    40 => "00000011101", 41 => "00000100010", 42 => "00000000100", 
    43 => "00000000000", 44 => "11111101101", 45 => "00000011101", 
    46 => "00000100011", 47 => "11111111100", 48 => "11110110000", 
    49 => "11110111110", 50 => "00000001110", 51 => "00000010011", 
    52 => "00000011010", 53 => "11111010011", 54 => "11111010000", 
    55 => "11111111101", 56 => "10010110101", 57 => "11110100101", 
    58 => "01010001110" );


begin 


memory_access_guard_0: process (address0) 
begin
      address0_tmp <= address0;
--synthesis translate_off
      if (CONV_INTEGER(address0) > AddressRange-1) then
           address0_tmp <= (others => '0');
      else 
           address0_tmp <= address0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(address0_tmp)); 
        end if;
    end if;
end process;

end rtl;

