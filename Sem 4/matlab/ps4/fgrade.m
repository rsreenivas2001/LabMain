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
## @deftypefn {} {@var{retval} =} fgrade (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Aravinthan Sreenivas <Aravinthan Sreenivas@ARAVINTHAN>
## Created: 2021-02-19
function g = fgrade (R)
    g = 1:size(R,1);
    for i = 1:size(R,1)
        hw = 0;
        min = R(i,1);
        for j = 1:10
            if(j<6)
                if(min > R(i,j))
                    min = R(i,j);
                endif
                hw = hw + R(i,j);
            endif            
        endfor
        hw = ((hw - min)/5)*1.5;
        mid = ((R(i,7))*0.15)+((R(i,8))*0.15)+((R(i,9))*0.15);
        final = R(i,10)*0.40;
        avgmid = (R(i,7)+R(i,8)+R(i,9))/3;
        if(avgmid > R(i,10))
           g(i) = avgmid*0.85 + hw;    
        else
           g(i) = mid + hw + final;
        endif        
    endfor
endfunction
