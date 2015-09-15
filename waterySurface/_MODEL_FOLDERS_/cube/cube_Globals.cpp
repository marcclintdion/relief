GLuint      cube_SHADER_VERTEX;                                                                                                      
GLuint      cube_SHADER_FRAGMENT;                                                                                                    
GLuint      cube_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_cube;   
GLuint      UNIFORM_MODELVIEW_cube;                                                                                             
GLuint      UNIFORM_LIGHT_MATRIX_cube;  
                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_cube;                                                                                          
GLuint      UNIFORM_SHININESS_cube;                                                                                                  
GLuint      UNIFORM_ATTENUATION_cube;                                                                                                  
GLuint      UNIFORM_TEXTURE_HEIGHT_cube;
GLuint      UNIFORM_TEXTURE_DOT3_cube;
GLuint      UNIFORM_TEXTURE_cube;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     cube_POSITION[]            =  {  -1.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     cube_ROTATE[]              =  {  1.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     cube_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   

//============================================================================== 
//==============================================================================                                                                      
  //__DPHOWARE_below
  GLfloat     cube_LIGHT_POSITION_01[] = {0, 3.34002, 54.9701, 1};
  GLfloat     cube_ATTENUATION         =  -0.00;
  GLfloat     cube_SHININESS           =  0.04;
//------------------------------------------------------------------------ 
//__TRISTEN_DEAN_codeSampler_below                 
  //GLfloat     cube_LIGHT_POSITION_01[] = {2, 15, 30, 1};
  //GLfloat     cube_ATTENUATION         =  0.001;
  //GLfloat     cube_SHININESS           =  0.000400022;
//==============================================================================                                               
//==============================================================================       


//-----------------------------------------------------------------                                                                       
GLuint      cube_VBO;
GLuint      cube_INDEX_VBO;                                                                                                                 
//-----------------------------------------------------------------                                                                       
GLuint      cube_HEIGHT; 
GLuint      cube_NORMALMAP;                                                                                                          
GLuint      cube_TEXTUREMAP;                                                                                                         
