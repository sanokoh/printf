make ft_printf
make printf
./ft_printf > ft_printf.txt
./printf > printf.txt
diff -a --suppress-common-lines ft_printf.txt printf.txt
vimdiff printf.txt ft_printf.txt
