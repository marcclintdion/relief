                   
                    if(cube_relief_HEIGHT != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &cube_relief_HEIGHT);                                                                  
                            cube_relief_HEIGHT = 0;                                                                                    
                    }                    
                    if(cube_relief_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &cube_relief_NORMALMAP);                                                                  
                            cube_relief_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(cube_relief_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &cube_relief_TEXTUREMAP);                                                                 
                            cube_relief_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(cube_relief_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &cube_relief_VBO);                                                                         
                            cube_relief_VBO  = 0;                                                                                         
                    }                                                                                                              
