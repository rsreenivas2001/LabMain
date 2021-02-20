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
## @deftypefn {} {@var{retval} =} mvssq (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Aravinthan Sreenivas <Aravinthan Sreenivas@ARAVINTHAN>
## Created: 2021-02-20

function [mean , variance ,sum ] = mvssq (inp)
  mean = sum(inp)/length(inp);
  temp = 1:length(inp);
  for i=1:length(inp)
    temp(i) = (inp(i) - mean)^2;
  endfor
  variance = sum(temp)/length(inp);
  sum = 0;
  for i=1:length(inp)
    sum = sum + inp(i)^2;
  endfor
endfunction
