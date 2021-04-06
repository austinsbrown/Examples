use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity top_level_tb is
end top_level_tb;

library ieee;
use IEEE.std_logic_1164.all;

architecture TEST of top_level_tb is
    signal RST, S, R, r_final, Y, y_final, G, g_final : std_logic;

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

    component clock_divider
        port 
        (
            clk   : in std_logic;
            clk_out  : out std_logic
        );
    end component;

  signal CLK : std_logic := '0';
  signal divided_clk : std_logic := '0';
  signal delay_clk : std_logic := '0';

begin

  process(CLK) -- clock pulse
  begin
    CLK <= not CLK after 1000 ns;
  end process;

    uut1 : CLOCK_DIVIDER port map 
    (
        clk, 
        divided_clk
    );
    uut2 : stop_light_logic port map 
    (
        RST, 
        S, 
        delay_clk, 
        R, 
        Y, 
        G
    ); 

  process
    variable counter : natural := 0;
    variable vline : LINE;
    variable V : std_logic_vector (5 downto 0); -- 6 bits
    variable VSPACE : character;
    file invect : text is "stimulus.txt";

  begin
    readline(invect, vline); 
    readline(invect, vline);
    read(vline, V(1 downto 0));
    read(vline, VSPACE);
    read(vline, V(4 downto 2));
    RST <= V(1);
    S <= V(0);
    r_final <= V(4);
    y_final <= V(3);
    g_final <= V(2);

    while not(ENDFILE(invect)) loop -- loop until end of file

      wait until divided_clk = '1';
      readline(invect, vline);
      read(vline, V(1 downto 0));
      read(vline, VSPACE);
      read(vline, V(4 downto 2));

      RST <= V(1);
      S <= V(0);
      r_final <= V(4);
      y_final <= V(3);
      g_final <= V(2);

      delay_clk <= divided_clk;

      wait until divided_clk = '0'; 
      delay_clk <= divided_clk;
      wait for 200 ns;

    end loop;
    wait;
  end process;
end TEST;

