# foreground colors

DEFCLR := '\e[39m'

BLACK := '\e[30m'
GRAYDARK := '\e[90m'
GRAYBRIGHT := '\e[37m'
WHITE := '\e[97m'

RED := '\e[31m'
RED_BRIGHT := '\e[91m'
GREEN := '\e[32m'
GREEN_BRIGHT := '\e[92m'
BLUE := '\e[34m'
BLUE_BRIGHT := '\e[94m'

CYAN := '\e[36m'
CYAN_BRIGHT := '\e[96m'
YELLOW := '\e[33m'
YELLOW_BRIGHT := '\e[93m'
MAGENTA := '\e[35m'
MAGNETA_BRIGHT := '\e[95m'


# background colors
DEFCLR_BG := '\e[49m'
BLACK_BG := '\e[40m'
GRAYDARK_BG := '\e[100m'
GRAYBRIGHT_BG := '\e[47m'
WHITE_BG := '\e[107m'

RED_BG := '\e[41m'
RED_BRIGHT_BG := '\e[101m'
GREEN_BG := '\e[42m'
GREEN_BRIGHT_BG := '\e[102m'
BLUE_BG := '\e[44m'
BLUE_BRIGHT_BG := '\e[104m'

CYAN_BG := '\e[46m'
CYAN_BRIGHT_BG := '\e[106m'
YELLOW_BG := '\e[48;5;3m'
YELLOW_BRIGHT_BG := '\e[103m'
MAGENTA_BG := '\e[45m'
MAGNETA_BRIGHT_BG := '\e[105m'


# font attributes

BOLD := '\e[1m'
NORMAL := '\e[22m'
DIM := '\e[2m'

ITALIC := '\e[3m'
ITALIC_OFF := '\e[23m'

UNDERLINE := '\e[4m'
UNDERLINE_OFF := '\e[24m'

REVERSE := '\e[7m'
REVERSE_OFF := '\e[27m'

STRIKE := '\e[9m'
STRIKE_OFF := '\e[29m'



define echovar
 echo -e $(BOLD)"${1}"$(BOLD_OFF)"  :=  ${${1}}"
endef

define title
 echo -e $(BLUE)"${1}"$(DEFCLR)
endef

define hr
 echo -e $(BOLD)"-------------------------------------------------------------------------------"$(BOLD_OFF)
endef
