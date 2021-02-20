## Copyright (C) 2021 Aravinthan Sreenivas
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} avgandsd (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Aravinthan Sreenivas <Aravinthan Sreenivas@ARAVINTHAN>
## Created: 2021-02-19
function [avg,sd] = avgandsd(x)
  sum = 0;
  sumation = 0;
  for i = x
    sum = sum + i;
  endfor
  avg = sum/length(x);
  for j = x
    sumation = sumation + (j - avg)^2;
  endfor
  sd = sqrt(sumation/length(x));
endfunction