# libczcomplex
Complex numbers based on libtomfloat

## Functions
All elementary functions as defined by Mathematica(TM), that is
<ul>
<li>Addition </li>
<li>Subtraction  </li>
<li>Multiplication  </li>
<li>Division  </li>
<li>Square root (all two branches)  </li>
<li>Logarithm (all branches)  </li>
<li>Power (all branches)   </li>
<li>Exponentiation base <code>e</code>  </li>
<li>Sine and relatives (sin, sinh, asin, asinh) </li>
<li>Cosine and relatives (cos, cosh, acos, acosh)  </li>
<li>Tangent and relatives (tan, tanh, atan, atanh, atan2)  </li>
<li>Lambert-W function (also known as ProductLog)  </li>
</ul>
Some helper functions
<ul>
<li>Norm  </li>
<li>Argument  </li>
<li>Magnitude (absolute value)  </li>
<li>Phase  </li>
<li>Negation  </li>
<li>Conjugate  </li>
<li>Multiplicative inverse  </li>
<li>Conversion: cartesian to polar representation  and vice versa</li>
<li>Isolate real part  </li>
<li>Isolate imaginary part  </li>
<li>&hellip; </li>
</ul>

Some functions may get added but mostly in the "helpers" department.

The comparing function, not listed above, is a bit special. It is not possible
to compare two complex values, so two complex numbers get compared first
for full equality (<code>a.re == b.re && a.im == b.im</code>) then
their magnitudes get collated and finally their phase angels.

Yes, it is costly.


## License
MIT, because the lobbying billionaires successfully bribed the lawmakers in such
a way that they made laws that de facto forbid me to put anything into public
domain because I cannot guarantee that it stays there.


