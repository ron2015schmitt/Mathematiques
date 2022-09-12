
#!/bin/bash
awk '
$1=="include" && NF>=2 {
   system("'$0' " $2)
   next
}
{print}' "$@"