import my_wrapper_c as mwc
a1 = mwc.generate_A(12)
a2 = mwc.generate_A(3)
b1 = mwc.generate_B(12)
mwc.print_B(b1)
mwc.print_A(a1)
l = [mwc.generate_A(1),mwc.generate_A(1),mwc.generate_A(1)]
print(l)
ax,a = mwc.sum_list_As(l)
print("added A")
mwc.print_A(ax)
print(a)
