    //=======================================================================================                                           
    /*if (keys['J'])                                                                                                                      
    {                                                                                                                                   
             relief_TristanDean_POSITION[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_POSITION[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_POSITION[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_POSITION[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_POSITION[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_POSITION[2]         -=  .01;                                                                                  
    }*/                                                                                                                                   
    //=======================================================================================                                           
    //=======================================================================================                                           
     if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             relief_TristanDean_LIGHT_POSITION_01[0]         -=  .11;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_LIGHT_POSITION_01[0]         +=  .11;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_LIGHT_POSITION_01[1]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_LIGHT_POSITION_01[1]         -=  .11;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_LIGHT_POSITION_01[2]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_LIGHT_POSITION_01[2]         -=  .11;                                                                            
    }                                                                                                                                 
    //=======================================================================================                                           
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_ATTENUATION                  +=  .0001;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_ATTENUATION                  -=  .0001;                                                                            
    }                                                                                                                                   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_SHININESS                  +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             relief_TristanDean_SHININESS                  -=   .01;                                                                                       
    }                                                                                                                                            
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("_MODEL_FOLDERS_/relief_TristanDean/relief_TristanDean_SHADER_SETTINGS.cpp");                                                                                     
        outKeys << "  GLfloat     relief_TristanDean_LIGHT_POSITION_01[] = {" << relief_TristanDean_LIGHT_POSITION_01[0] << ", "                               
                                                                       << relief_TristanDean_LIGHT_POSITION_01[1] << ", "                               
                                                                       << relief_TristanDean_LIGHT_POSITION_01 [2] << ", " << 1.0 << "};\n";          
        outKeys << "  GLfloat     relief_TristanDean_ATTENUATION         =  " << relief_TristanDean_ATTENUATION   << ";\n";                                    
        outKeys << "  GLfloat     relief_TristanDean_SHININESS           =  " << relief_TristanDean_SHININESS  << ";\n";                                       
    }                                                                                                                                            
