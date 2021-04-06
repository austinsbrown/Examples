CC = ghdl

default:
	make clock_divider.vcd
	make stop_light_logic.vcd
	make top_level.vcd

clock_divider.vcd: clock_divider_tb.vhd clock_divider.vhd
	$(CC) -a clock_divider.vhd
	$(CC) -a clock_divider_tb.vhd
	$(CC) -e clock_divider_tb
	$(CC) -r clock_divider_tb --vcd=clock_divider.vcd --stop-time=3ms

stop_light_logic.vcd: stop_light_logic.vhd stop_light_logic_tb.vhd
	$(CC) -a stop_light_logic.vhd
	$(CC) -a stop_light_logic_tb.vhd
	$(CC) -e stop_light_logic_tb
	$(CC) -r stop_light_logic_tb --vcd=stop_light_logic.vcd --stop-time=50ns

top_level.vcd: clock_divider.vhd stop_light_logic.vhd top_level.vhd top_level_tb.vhd
	$(CC) -a clock_divider.vhd
	$(CC) -a stop_light_logic.vhd
	$(CC) -a top_level.vhd
	$(CC) -a --ieee=synopsys top_level_tb.vhd
	$(CC) -e  --std=08 top_level_tb
	$(CC) -r top_level_tb --vcd=top_level.vcd --stop-time=100ns

clean:
	rm clock_divider.vcd stop_light_logic.vcd top_level.vcd work*
