library ieee;
use ieee.std_logic_1164.all;

entity stop_light_logic_tb is
end stop_light_logic_tb;

architecture test of stop_light_logic_tb is
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

    signal reset, start, clock, red, yellow, green : std_logic;
    constant clk_t : time := 2 ns; 
begin
    uut : stop_light_logic port map
    (
        reset,
        start,
        clock,
        red, 
        yellow,
        green
    );

    clock_control : process 
    begin
        clock <= '0';
        wait for clk_t / 2;
        clock <= '1';
        wait for clk_t / 2;
    end process;

    stimuli : process
    begin
        reset <= '1';
        wait for 2 ns;

        reset <= '0';
        start <= '1';
        wait for 2 ns;

        start <= '0';
        wait for 30 ns;
        start <= '1';
        wait for 2 ns;
        start <= '0';
        wait;
    end process;
end architecture;