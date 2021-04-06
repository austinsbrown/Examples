ghdl -a ha.vhd
ghdl -a ha_tb.vhd
ghdl -e ha_tb
ghdl -r ha_tb --vcd=dump.vcd