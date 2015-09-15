# relief 

This shader group is based on the Relief Map shader that was posted by Tristan Dean in 2007.
http://www.codesampler.com/usersrc/usersrc_5.htm#oglu_glslang_relief_mapping

It's best suited for models that will not be using much screen space since the binary search adds substantial overhead.
For larger models, the stepping pattern becomes obvious at glancing angles.  

The illusion of depth it gives at higher frequencies is impressive.  
For large models, especially, ground and sidewalls, 
cone-step mapping is likely the best looking and most efficient choice for texture distortion based effects.  

Maybe this would be good for front facing walls in situations where CSM is causing issues with inner-depth displacement.

Texture coordinate seams are obvious using these shaders.  
Not sure how to deal with this other than to make sure all seams areas have 0.0 height.

