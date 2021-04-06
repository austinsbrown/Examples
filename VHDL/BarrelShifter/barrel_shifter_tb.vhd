use work.all;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity barrel_shifter_tb is
end barrel_shifter_tb;

architecture BARREL_TEST of barrel_shifter_tb is
    signal RUN : BIT;
    signal c : std_logic_vector (7 downto 0); 
    signal PG : BIT_VECTOR (11 downto 0); -- output of the pulse gen
    signal temp : std_logic_vector (11 downto 0); -- pulse gen converted to std_logic

    component barrel_shifter
        port
        (
            a : in std_logic_vector (7 downto 0); 
            s : in std_logic_vector (2 downto 0);
            en : in std_logic;
            c : out std_logic_vector (7 downto 0)
        );
    end component;


begin
    L1 : barrel_shifter
        port map -- map bits of std_logic to inputs of barrel shifter
        (
            temp(10 downto 3), -- a
            temp(2 downto 0), -- s
            temp(11), -- en
            c
        );

    L2 : entity PULSE_GEN(alg)
        generic map(12, 10 ns)
        port map(RUN, PG);

    temp <= to_stdlogicvector(PG);
    process
    begin
        RUN <= '1', '0' after 1 ns;
        wait;
    end process;
end BARREL_TEST;
