ghdl -a barrel_shifter.vhd
ghdl -a pulse_gen.vhd
ghdl -a barrel_shifter_tb.vhd
ghdl -e barrel_shifter_tb
ghdl -r barrel_shifter_tb --vcd=dump.vcd