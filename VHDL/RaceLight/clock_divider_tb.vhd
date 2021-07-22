use work.all;
library ieee;
use ieee.std_logic_1164.all;

entity clock_divider_tb is
end clock_divider_tb;

architecture test of clock_divider_tb is
	component clock_divider
		port
		(
			clk: in std_logic;
			clk_out : out std_logic
		);
	end component;

	signal clk : std_logic := '0';
	signal clk_out : std_logic;
	constant clk_t : time := 10 ns; 
begin
	-- Instance of unit under test.
	uut : clock_divider PORT MAP 
    (
		clk => clk,
		clk_out => clk_out
	);

	clock : process
		begin
			clk <= '0';
			wait for clk_t / 2;
			clk <= '1';
			wait for clk_t / 2;
		end process;

	-- Processing.
	stimuli: process
	begin
        wait;
	end process;
END;