    glUseProgram(facing_UP_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, facing_UP_VBO); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facing_UP_INDEX_VBO);                                                                                                                                   
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);
    LoadIdentity(rotationMatrix);                                                                                                                                                      
    Translate(modelView, moveSet[0], moveSet[1], moveSet[2]);      
    Translate(modelView, facing_UP_POSITION[0], facing_UP_POSITION[1], facing_UP_POSITION[2]);                                                                                         
    Rotate(modelView, facing_UP_ROTATE[0], facing_UP_ROTATE[1], facing_UP_ROTATE[2], facing_UP_ROTATE[3]);//--MODEL                                                                       
    Rotate(modelView, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
    Rotate(modelView, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);     
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    //InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    
//mtxInvert(lightMatrix, modelView);    
//mtxTranspose(lightMatrix, modelView);  
  
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    
   //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    glVertexAttribPointer(3,   2, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(36));                                                                                                 
    glEnableVertexAttribArray(3);                                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_facing_UP, facing_UP_LIGHT_POSITION_01[0], facing_UP_LIGHT_POSITION_01[1], facing_UP_LIGHT_POSITION_01[2], facing_UP_LIGHT_POSITION_01[3]);        
    glUniform4f(UNIFORM_linearTransform_facing_UP , facing_UP_POSITION[0], facing_UP_POSITION[1], facing_UP_POSITION[2], facing_UP_POSITION[3]);        
    
    glUniform1f(UNIFORM_SHININESS_facing_UP, facing_UP_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_facing_UP, facing_UP_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_facing_UP,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_facing_UP,   1,0,      modelView); 
    glUniformMatrix4fv(UNIFORM_ROTATIONMATRIX_facing_UP,   1,0,      rotationMatrix);                                                                                                             
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_facing_UP,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_HEIGHT_facing_UP, 2);     
    glUniform1i (UNIFORM_TEXTURE_DOT3_facing_UP, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_facing_UP, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, facing_UP_HEIGHT);                                                                                                                          
    //---     
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, facing_UP_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, facing_UP_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawElements(GL_TRIANGLES, 600, GL_UNSIGNED_INT, 0);
