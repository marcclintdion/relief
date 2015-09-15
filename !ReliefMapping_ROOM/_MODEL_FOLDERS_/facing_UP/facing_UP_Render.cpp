    glUseProgram(facing_UP_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, facing_UP_VBO); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facing_UP_INDEX_VBO);                                                                                                                                   
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, moveSet[0], moveSet[1], moveSet[2]);    
    Rotate(modelView, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
    Rotate(modelView, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);     
    //------------------------------------------------------------------------------------------------------------------------------------    
    Translate(modelView, facing_UP_POSITION[0], facing_UP_POSITION[1], facing_UP_POSITION[2]);                                                                                         
    Rotate(modelView, facing_UP_ROTATE[0], facing_UP_ROTATE[1], facing_UP_ROTATE[2], facing_UP_ROTATE[3] );                                                                      
    Rotate(modelView, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);    
    Rotate(modelView, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
         
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     

    //mtxInvert(lightMatrix, modelView);                                                                                                                                     
    //mtxTranspose(lightMatrix, modelView);    
                                                                                                                    
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   3, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    glVertexAttribPointer(3,   2, GL_FLOAT, GL_FALSE, 44, BUFFER_OFFSET(36));                                                                                                 
    glEnableVertexAttribArray(3);                                                                                                                                                
    //======================================================================================================                
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_facing_UP,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_facing_UP,   1,0,      modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_facing_UP,    1,0,  lightMatrix);                                                                                                    
    //---------------------------------------------------------------------------------
  
   // float angle_rad        =  rotateModelWithLeftMouse[0] * 3.14159 / -180.0;
   // facing_UP_LIGHT_POSITION_01[0]             =  facing_UP_POSITION[0] * cos(angle_rad) + facing_UP_POSITION[1] * sin(angle_rad);
   // facing_UP_LIGHT_POSITION_01[1]             = -facing_UP_POSITION[0] * sin(angle_rad) + facing_UP_POSITION[1] * cos(angle_rad);   
      
    //facing_UP_LIGHT_POSITION_01[0]  = facing_UP_LIGHT_POSITION_01[1] * cos(angle_rad)  + facing_UP_LIGHT_POSITION_01[2] * sin(angle_rad);
    // facing_UP_LIGHT_POSITION_01[2]  = -facing_UP_LIGHT_POSITION_01[1] * sin(angle_rad) + facing_UP_LIGHT_POSITION_01[2] * cos(angle_rad);  
   
   
    glUniform4f(UNIFORM_LIGHT_POSITION_01_facing_UP, facing_UP_LIGHT_POSITION_01[0], 
                                                     facing_UP_LIGHT_POSITION_01[1], 
                                                     facing_UP_LIGHT_POSITION_01[2], 
                                                     facing_UP_LIGHT_POSITION_01[3]);        
    //---------------------------------------------------------------------------------    
    glUniform1f(UNIFORM_QUADRATIC_ATTENUATION_facing_UP, facing_UP_quadraticAttenuation);    
    glUniform1f(UNIFORM_LINEAR_ATTENUATION_facing_UP,    facing_UP_linearAttenuation); 
    glUniform1f(UNIFORM_CONSTANT_ATTENUATION_facing_UP,  facing_UP_constantAttenuation); 
    //---------------------------------------------------------------------------------     
    glUniform1f(UNIFORM_SHININESS_facing_UP, facing_UP_SHININESS);     
    glUniform1f(UNIFORM_zDirBias_facing_UP, zDirectionBias);              
    //---------------------------------------------------------------------------------    
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
