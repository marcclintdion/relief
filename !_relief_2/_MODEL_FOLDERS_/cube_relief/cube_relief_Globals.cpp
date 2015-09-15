GLuint      cube_relief_SHADER_VERTEX;                                                                                                      
GLuint      cube_relief_SHADER_FRAGMENT;                                                                                                    
GLuint      cube_relief_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_cube_relief;   
GLuint      UNIFORM_MODELVIEW_cube_relief;  
GLuint      UNIFORM_ROTATIONMATRIX_cube_relief;                                                                                            
GLuint      UNIFORM_LIGHT_MATRIX_cube_relief;  
                                                                                             
//--------------------------------------            
GLuint      UNIFORM_linearTransform_cube_relief;                                                                                                 
GLuint      UNIFORM_LIGHT_POSITION_01_cube_relief;                                                                                          
GLuint      UNIFORM_SHININESS_cube_relief;                                                                                                  
GLuint      UNIFORM_ATTENUATION_cube_relief;                                                                                                  
GLuint      UNIFORM_TEXTURE_HEIGHT_cube_relief;
GLuint      UNIFORM_TEXTURE_DOT3_cube_relief;
GLuint      UNIFORM_TEXTURE_cube_relief;                                                                                                    
//--------------------------------------                                                                                                  
var         cube_relief_POSITION[]    =  {0, 0, 0, 1.0};
GLfloat     cube_relief_ROTATE[]              =  {  1.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     cube_relief_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
GLfloat     linearTransform[]                 =  {  0.0, 0.0, 0.0, 1.0};
//============================================================================== 
//==============================================================================                                                                      
  //__DPHOWARE_below
  GLfloat     cube_relief_LIGHT_POSITION_01[] = {0.0, 3.34002, -10.9701, 1};

var         cube_relief_ATTENUATION            =  -0;
var         cube_relief_SHININESS              =  50.0;
//------------------------------------------------------------------------ 
//__TRISTEN_DEAN_codeSampler_below                 
  //GLfloat     cube_relief_LIGHT_POSITION_01[] = {2, 15, 30, 1};
  //GLfloat     cube_relief_ATTENUATION         =  0.001;
  //GLfloat     cube_relief_SHININESS           =  0.000400022;
//==============================================================================                                               
//==============================================================================       


//-----------------------------------------------------------------                                                                       
GLuint      cube_relief_VBO;
GLuint      cube_relief_INDEX_VBO;                                                                                                                 
//-----------------------------------------------------------------                                                                       
GLuint      cube_relief_HEIGHT; 
GLuint      cube_relief_NORMALMAP;                                                                                                          
GLuint      cube_relief_TEXTUREMAP;                                                                                                         
