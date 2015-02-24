unitsize(1cm);
import libdado;

picture pic = dado(f = 2, t = 1, r = 3, show_axes = true);
add(pic.fit(4cm), (0,0), N);