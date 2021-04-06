library ieee;
use ieee.std_logic_1164.all;

entity stop_light_logic is
    port
    (
        reset : in std_logic;
        start : in std_logic;
        clock : in std_logic;

        red : out std_logic;
        yellow : out std_logic;
        green : out std_logic
    );
end stop_light_logic;

architecture behav of stop_light_logic is

    type state_type is (reset_state, red_state, yellow_state, green_state1, green_state2, green_state3); 
    signal state : state_type; -- holds the state
    signal count : integer := 0; -- used to keep track of time
    signal red_t, yellow_t, green_t : std_logic; -- used to keep from infering latches
    begin
        state_process : process(clock) -- controls what the state is
        begin
            if(reset = '1') then 
                state <= reset_state;

            elsif(start = '1' and state = reset_state) then 
                state <= red_state;
                
            elsif(state = red_state) then
                state <= yellow_state;

            elsif(state = yellow_state) then
                state <= green_state1;

            elsif(state = green_state1) then
                state <= green_state2;

            elsif(state = green_state2) then
                state <= green_state3;

            elsif(state = green_state3) then
                state <= reset_state;
            else
                state <= reset_state;
            end if;
        end process;

        output_process : process(state, red_t, green_t, yellow_t) -- controls what the output is
        begin
            if(state = reset_state) then -- reset
                red_t <= '1';
                yellow_t <= '0';
                green_t <= '0';
            elsif(state = red_state) then -- red light
                red_t <= '1';
                yellow_t <= '0';
                green_t <= '0';
            elsif(state = yellow_state) then -- yellow light
                red_t <= '0';
                yellow_t <= '1';
                green_t <= '0';
            elsif(state = green_state1) then -- green light
                red_t <= '0';
                yellow_t <= '0';
                green_t <= '1';

            elsif(state = green_state2) then -- green light
                red_t <= '0';
                yellow_t <= '0';
                green_t <= '1';

            elsif(state = green_state3) then -- green light
                red_t <= '0';
                yellow_t <= '0';
                green_t <= '1';
            end if;
        end process;

        red <= red_t;
        yellow <= yellow_t;
        green <= green_t;
end architecture;