library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ha is
    port
    (
        a : in std_logic;
        b : in std_logic;
        o : out std_logic;
        c : out std_logic
    );
end ha;

architecture behave of ha is
begin 
    o <= a xor b;
    c <= a and b;    
end behave;