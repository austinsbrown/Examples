library ieee;
use ieee.std_logic_1164.all;

entity top_level is
    port
    (
        reset : in std_logic;
        start : in std_logic;
        clock : in std_logic;

        red : out std_logic;
        yellow : out std_logic;
        green : out std_logic
    );
end top_level;

architecture behav of top_level is
    component clock_divider
		port
		(
			clk: in std_logic;
			clk_out : out std_logic
		);
	end component;

    component stop_light_logic
        port
        (
            reset : in std_logic;
            start : in std_logic;
            clock : in std_logic;

            red : out std_logic;
            yellow : out std_logic;
            green : out std_logic
        );
    end component;

    signal divided_clock : std_logic;
begin
    c_d : clock_divider port map
    (
        clock,
        divided_clock
    );

    s_l_l : stop_light_logic port map
    (
        reset,
        start,
        divided_clock,
        red, 
        yellow,
        green
    );    
end architecture;