
source style.bash

ncolors
longname
echo -e "Hello there! <- Normal"
echo -e "${BOLD}Hello there!${NORMAL} <- BOLD"
echo -e "${DIM}Hello there!${NORMAL} <- DIM"
echo -e "${ITALIC}Hello there!${ITALIC_OFF} <- ITALIC"
echo -e "${UNDERLINE}Hello there!${UNDERLINE_OFF} <- UNDERLINE"
echo -e "${BOLD}${ITALIC}Hello there!${NORMAL}${ITALIC_OFF} <- BOLD+ITALIC"
echo -e "${REVERSE}Hello there!${REVERSE_OFF} <- REVERSE"
echo -e "Hello there! <- Normal"
echo -e "${BLUE}Hello there!${DEFCLR} <- BLUE"
echo -e "${BOLD}${BLUE}Hello there!${DEFCLR}${NORMAL} <- BOLD BLUE"   
echo -e "${BLUE}${BOLD}Hello there!${NORMAL}${DEFCLR} <- BLUE BOLD"   
echo -e "${BLUE}Hello there!${DEFCLR} <- BLUE"
echo -e "${YELLOW_BG}Hello there!${DEFCLR_BG} <- HIGHLIGHT"
