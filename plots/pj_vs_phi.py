import polarization_plots as pp
import numpy as np
import matplotlib.pyplot as plt

path=r"../rhic_2060iso/primary"
path2=r"../rhic_2060new/primary"
path3=r"../rhic_2060new_nochem_gradT/primary"
path4=r"../rhic_2060new_nochem/primary"
path5=r"../rhic_2060new_gradT/primary"
path6=r"../rhic_2060new_fixednorm/primary"
path7=r"../rhic_2060iso_fixednorm/primary"

x, y = pp.Sj_rapidity_polarization(path, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
a, b = pp.Sj_rapidity_polarization(path2, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
c, d = pp.Sj_rapidity_polarization(path3, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
e, f = pp.Sj_rapidity_polarization(path4, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
g, h = pp.Sj_rapidity_polarization(path5, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
i, j = pp.Sj_rapidity_polarization(path6, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)
k, l = pp.Sj_rapidity_polarization(path7, mass=1.115683, rap_cut=1, pt_cut=10, vorticity=False, global_integrals = False)

plt.plot(x, 2*y, marker='o', linestyle='-', color='blue', label='iso')
plt.plot(a, 2*b, marker='s', linestyle='-', color='red', label='new')
plt.plot(c, 2*d, marker='d', linestyle='-', color='green', label='new_nochem_gradT')
plt.plot(e, 2*f, marker='^', linestyle='-', color='orange', label='new_nochem')
plt.plot(g, 2*h, marker='x', linestyle='-', color='purple', label='new_gradT')
#plt.plot(i, 2*j, marker='v', linestyle='-', color='brown', label='new_fixednorm')
#plt.plot(k, 2*l, marker='v', linestyle='-', color='cyan', label='iso_fixednorm')
plt.xlabel(r"$\phi$")
plt.ylabel(r"$\langle P_J\rangle$")
plt.legend(loc='lower right')
plt.title(r"AuAu $\sqrt{s_{NN}}=200$ GeV 20/60")
plt.show()
