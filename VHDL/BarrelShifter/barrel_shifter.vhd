library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity barrel_shifter is 
    port 
    (
        a : in std_logic_vector (7 downto 0); -- the input to be shifted
        s : in std_logic_vector (2 downto 0); -- how much to shift by
        en : in std_logic; -- enable bit
        c : out std_logic_vector (7 downto 0) -- shifted output
    );
end entity barrel_shifter;

architecture behav of barrel_shifter is
begin
    main : process(a, s, en) -- watch for any of the inputs to change
    begin
        if en = '0' then c <= "ZZZZZZZZ"; -- handle the enable bit
        else
            case s is -- do the shifting with concatonation
                when "000" => c <= a;
                when "001" => c <= a(0) & a(7 downto 1);
                when "010" => c <= a(1 downto 0) & a(7 downto 2);
                when "011" => c <= a(2 downto 0) & a(7 downto 3);
                when "100" => c <= a(3 downto 0) & a(7 downto 4);
                when "101" => c <= a(4 downto 0) & a(7 downto 5);
                when "110" => c <= a(5 downto 0) & a(7 downto 6);
                when "111" => c <= a(6 downto 0) & a(7);
                when others => c <= "ZZZZZZZZ";
            end case;
        end if;
    end process;
end behav; 