/**
 * 	Opis: Obraca punkt o kąt \texttt{ang}.
 */

void rot(double& x, double& y, double ang)
{
	double nx = x*cos(ang) - y*sin(ang);
	double ny = x*sin(ang) + y*cos(ang);
	x = nx;
	y = ny;
	return;
} 
