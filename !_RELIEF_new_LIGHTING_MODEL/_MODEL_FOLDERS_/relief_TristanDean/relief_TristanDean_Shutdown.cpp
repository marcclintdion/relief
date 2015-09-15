                   
                    if(relief_TristanDean_HEIGHT != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &relief_TristanDean_HEIGHT);                                                                  
                            relief_TristanDean_HEIGHT = 0;                                                                                    
                    }                    
                    if(relief_TristanDean_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &relief_TristanDean_NORMALMAP);                                                                  
                            relief_TristanDean_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(relief_TristanDean_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &relief_TristanDean_TEXTUREMAP);                                                                 
                            relief_TristanDean_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(relief_TristanDean_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &relief_TristanDean_VBO);                                                                         
                            relief_TristanDean_VBO  = 0;                                                                                         
                    }                                                                                                              
