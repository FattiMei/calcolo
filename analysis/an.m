sol_esatta = @(x) exp(x);
risultati = load('problema11_50step');


mesh = risultati(:, 1);

u	= sol_esatta(mesh);
u_tilde = risultati(:, 2:);
