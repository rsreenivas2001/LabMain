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
## @deftypefn {} {@var{retval} =} fun3 (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Aravinthan Sreenivas <Aravinthan Sreenivas@ARAVINTHAN>
## Created: 2021-02-19

function [ output_args ] = function_3( input_args )
    output_args = (-0.2.*(input_args.^4)) + ((exp(-0.5.*input_args)) .* (input_args.^3)) + (7 .* (input_args.^2));
end
