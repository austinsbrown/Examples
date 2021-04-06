library ieee;
use ieee.std_logic_1164.all;

entity clock_divider is
    port 
    (
        clk : in  std_logic;
        clk_out: out std_logic
    );
end clock_divider;

architecture behav of clock_divider is
    signal temp: std_logic := '0';
    signal count : integer range 0 to 500000 := 0;
begin
    divide: process (clk) begin
        if(rising_edge(clk)) then
            if (count < (500000/2)-1) then
                count <= count + 1;
                temp <= '1';
            elsif(count < 500000-1) then
                count <= count + 1;
                temp <= '0';
            else
                count <= 0;
                temp <= '1';
            end if;
        end if;
        
        clk_out <= temp;
    end process;
end behav;