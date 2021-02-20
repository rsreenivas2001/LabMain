x = linspace(-2,4);

func = 3.*((x).^3)-26.*x+10;
func_first = diff(func);
func_second = diff(func_first);
vec_1 = x(1:end-1);
vec_2 = x(1:end-2);
plot(x, func)
hold on
plot(vec_1, func_first)
hold on
plot(vec_2, func_second)
