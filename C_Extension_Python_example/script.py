import my_wrapper_c as mwc
a1 = mwc.generate_A(True)
a2 = mwc.generate_A(False)
mwc.print_A(a1)
l = [mwc.generate_A(True),mwc.generate_A(False),mwc.generate_A(True)]
print(l)
ax,a = mwc.sum_list_As([1,0,0])
print("added A")
mwc.print_A(ax)
print(a)
