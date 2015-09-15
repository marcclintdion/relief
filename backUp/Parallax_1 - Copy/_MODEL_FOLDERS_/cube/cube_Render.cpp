    glUseProgram(cube_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, cube_VBO); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_INDEX_VBO);                                                                                                                                   
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, cube_POSITION[0], cube_POSITION[1], cube_POSITION[2]);                                                                                         
    Rotate(modelView, cube_ROTATE[0], cube_ROTATE[1], cube_ROTATE[2], cube_ROTATE[3] );                                                                      
    Rotate(modelView, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
    Rotate(modelView, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);         
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                         
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 56, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 56, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   3, GL_FLOAT, GL_FALSE, 56, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    glVertexAttribPointer(3,   3, GL_FLOAT, GL_FALSE, 56, BUFFER_OFFSET(36));                                                                                                 
    glEnableVertexAttribArray(3);      
    glVertexAttribPointer(4,   2, GL_FLOAT, GL_FALSE, 56, BUFFER_OFFSET(48));                                                                                                 
    glEnableVertexAttribArray(4);                                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_cube, cube_LIGHT_POSITION_01[0], cube_LIGHT_POSITION_01[1], cube_LIGHT_POSITION_01[2], cube_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_cube, cube_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_cube, cube_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_cube,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_cube,   1,0,      modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_cube,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_HEIGHT_cube, 2);     
    glUniform1i (UNIFORM_TEXTURE_DOT3_cube, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_cube, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, cube_HEIGHT);                                                                                                                          
    //---     
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, cube_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, cube_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
