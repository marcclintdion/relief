     #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      cube_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_cube =                                                                                                        

      "    #define highp                                                                                        \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                            \n"                           
      "    uniform         mat4   mvpMatrix;                                                                    \n"                           
      "    uniform         mat4   mvMatrix;                                                                     \n"        
      "    uniform         mat4   lightMatrix;                                                                  \n"                           

      "    attribute       vec4   position;                                                                     \n"                           
      "    attribute       vec3   normal;                                                                       \n"         
      "    attribute       vec3   tangent;                                                                      \n"             
      "    attribute       vec3   bitangent;                                                                      \n"       
      
      "    attribute       vec2   texture;                                                                      \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                             \n"                           
      "    varying highp vec3   EyeDir;                                                                        \n"           
      "    varying highp vec2   varTexcoord;                                                                    \n"                           

      "    vec3 view;                                                                                           \n"    

      "    void main()                                                                                          \n"                           
      "    {                                                                                                    \n"                           
      
      "      vec3 n =  (mvMatrix * vec4(normal, 0.0));                                                         \n"  
      "      vec3 t =  (mvMatrix * vec4(tangent, 0.0));                                                        \n"  
      "      vec3 b =  (mvMatrix * vec4(bitangent, 0.0));                                                      \n"        
      //"      vec3 b =   cross(n, t);                                                                            \n"  
  
      "      mat3 tbnMatrix = mat3(t.x, b.x, n.x,                                                               \n"  
      "                            t.y, b.y, n.y,                                                               \n"  
      "                            t.z, b.z, n.z);                                                              \n"  
    
    
      "        vec3 vertexPosition   =  position;                                         \n"        
      "        vec3 dirEye           =  vec3(0.0,0.0, -1000.0) - vertexPosition;                          \n"  
      
      "        EyeDir.x              =  dot(t.xyz , dirEye);                                                    \n"  
      "        EyeDir.y              =  dot(b.xyz , dirEye);                                                    \n"  
      "        EyeDir.z              =  dot(n.xyz , dirEye);                                                    \n"  
     //-----------------------------------------------------------------------------------------------------------------
      "      lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                   \n"                           

      "      varTexcoord        = texture;                                                                      \n"                           

      "      gl_Position        = mvpMatrix * position;                                                         \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      cube_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(cube_SHADER_VERTEX, 1, &vertexSource_cube, NULL);                                                                        
      glCompileShader(cube_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_cube =                                                                                                            

      " #ifdef GL_ES                                                                                                                               \n"                       
      " #else                                                                                                                                      \n"                       
      " #define highp                                                                                                                              \n"                       
      " #endif                                                                                                                                     \n"                       

      "    uniform sampler2D     Texture1;                                                                                                         \n"                       
      "    uniform sampler2D     NormalMap;                                                                                                        \n"                       
      "    uniform sampler2D     HeightMap;                                                                                                        \n"        
      "    uniform highp float   shininess;                                                                                                        \n"                       
      "    uniform highp float   attenuation;                                                                                                      \n"                       
      "    uniform highp vec4    light_POSITION_01;                                                                                                \n"    
      "    varying highp vec4    lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec3    EyeDir;                                                                                                          \n"     
      
      "    varying highp vec2    varTexcoord;                                                                                                      \n"                       

      "            highp float   NdotL1;                                                                                                           \n"                       
      "            highp vec3    normal;                                                                                                           \n"                       
      "            highp vec3    NormalTex;                                                                                                        \n"                       

      "            highp float   scale;                                                                                                            \n"  
      "            highp float   bias;                                                                                                             \n"  


      "     void main()                                                                                                                            \n"                       
      "     {                                                                                                                                      \n"                       
                      

      "         highp vec2 newTexCoord;                                                                                                            \n"  
      "         highp vec3 v = normalize(EyeDir);                                                                                                 \n"    

      "         highp float height = texture2D(HeightMap, varTexcoord.xy).r;                                                                       \n"  
        
      "         height = height * shininess + attenuation;                                                                                         \n"  
      "         newTexCoord = varTexcoord.xy + (height * -v.xy);                                                                                  \n"  
      
      //------------------------------------------------------------------------------------------------------------------------
      
      "         NormalTex   =  texture2D(NormalMap,  newTexCoord).xyz;                                                                             \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                                                         \n"                       
      "         normal                =  normalize(NormalTex);                                                                                     \n"      
      "         NdotL1                =  dot(normal, normalize(light_POSITION_01.xyz));                                                            \n"                       

      //------------------------------------------------------------------------------------------------------------------------      
      
      "         gl_FragColor          =  vec4(1.0, 1.0, 1.0, 1.0) * .1                                                                        \n"                       

      "                               +  texture2D(Texture1, newTexCoord.xy) * NdotL1 * NdotL1 * 0.5                                                        \n"                       

      "                               +  texture2D(Texture1, newTexCoord.xy) * pow(NdotL1, 50.0) * vec4(2.0, 1.0, .1, 1.0)*1.0;                  \n"                       

      "    }\n";                                                                                                                                   

    
/*   
      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      cube_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_cube =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec3   normal;                                                                      \n"         
      "    attribute       vec3   tangent;                                                                     \n"             
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           

      "    varying highp vec3   EyeDir;                                                                        \n"   
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    vec3 view;                                                                                          \n"    

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      
      "        vec3 m_Tangent = -vec3(mvpMatrix * vec4(tangent, 0.0));                                          \n" 
      "        vec3 m_Normal  = -vec3(mvpMatrix * vec4(normal, 0.0));                                            \n" 
      
      "        vec3 m_BiNormal = cross(m_Normal, m_Tangent);                                                    \n"  
  
      "        vec3 m_Vector = (lightMatrix * position).xyz;                                                     \n" 

      "        vec3  dirEye   = vec3(0.0, 0.0, 0.0) - m_Vector;                                                \n" 
                                              
      "        EyeDir.x = dot(m_Tangent, dirEye);                                                              \n" 
      "        EyeDir.y = dot(m_BiNormal , dirEye);                                                           \n" 
      "        EyeDir.z = dot(m_Normal , dirEye);                                                              \n"   
      
//------------------------------------------------------------------------------------------------------------------------      
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      cube_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(cube_SHADER_VERTEX, 1, &vertexSource_cube, NULL);                                                                        
      glCompileShader(cube_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_cube =                                                                                                            

      " #ifdef GL_ES                                                                                                                               \n"                       
      " #else                                                                                                                                      \n"                       
      " #define highp                                                                                                                              \n"                       
      " #endif                                                                                                                                     \n"                       

      "    uniform sampler2D     Texture1;                                                                                                         \n"                       
      "    uniform sampler2D     NormalMap;                                                                                                        \n"                       
      "    uniform sampler2D     HeightMap;                                                                                                        \n"       
      "    uniform highp float   shininess;                                                                                                        \n"                       
      "    uniform highp float   attenuation;                                                                                                      \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                                               \n"                       

      "    varying highp vec3    EyeDir;                                                                                                           \n"         
      
      "    varying highp vec2    varTexcoord;                                                                                                      \n"                       

      "            highp float   NdotL1;                                                                                                           \n"                       
      "            highp vec3    normal;                                                                                                           \n"                       
      "            highp vec3    NormalTex;                                                                                                        \n"                       


      "     void main()                                                                                                                            \n"                       
      "     {                                                                                                                                      \n"                       
                      
      "         vec3 EyeT       = normalize(EyeDir);                                                                                               \n"  
      "         vec4 Offset     = texture2D(HeightMap, varTexcoord. xy);                                                                               \n"  
      "         Offset          = Offset * shininess - attenuation;                                                                                            \n" 
      "         vec2 TexCoords  = Offset.xy * EyeT.xy + varTexcoord;                                                                               \n" 
  
      //------------------------------------------------------------------------------------------------------------------------
      
      "         NormalTex   =  texture2D(NormalMap,  TexCoords.xy).xyz;                                                                             \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                                                         \n"                       
      "         normal                =  normalize(NormalTex);                                                                                     \n"      
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                                                      \n"                       

      //------------------------------------------------------------------------------------------------------------------------      
      
      "         gl_FragColor          =  texture2D(Texture1, TexCoords.xy) *  0.0                                                                \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * NdotL1* 1.0                                       \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * pow(NdotL1, 50.0) * vec4(2.0, 1.0, .1, 1.0)*0.0;                       \n"                       

      "    }\n";    
*/



      //---------------------------------------------------------------------                                                                         
      cube_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(cube_SHADER_FRAGMENT, 1, &fragmentSource_cube, NULL);                                                                          
      glCompileShader(cube_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(cube_SHADER, cube_SHADER_VERTEX);                                                                                              
      glAttachShader(cube_SHADER, cube_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(cube_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(cube_SHADER, 1, "normal");       
      glBindAttribLocation(cube_SHADER, 2, "tangent");  
      glBindAttribLocation(cube_SHADER, 3, "bitangent");               
      glBindAttribLocation(cube_SHADER, 4, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(cube_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(cube_SHADER, cube_SHADER_VERTEX);                                                                                              
      glDetachShader(cube_SHADER, cube_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(cube_SHADER_VERTEX);                                                                                                            
      glDeleteShader(cube_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_cube                   = glGetUniformLocation(cube_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_cube                       = glGetUniformLocation(cube_SHADER,   "mvMatrix");        
      UNIFORM_LIGHT_MATRIX_cube                    = glGetUniformLocation(cube_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_cube               = glGetUniformLocation(cube_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_cube                       = glGetUniformLocation(cube_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_cube                     = glGetUniformLocation(cube_SHADER,   "attenuation");
      UNIFORM_TEXTURE_HEIGHT_cube                  = glGetUniformLocation(cube_SHADER,   "HeightMap");                                                      
      UNIFORM_TEXTURE_DOT3_cube                    = glGetUniformLocation(cube_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_cube                         = glGetUniformLocation(cube_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"cube_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &cube_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, cube_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"cube" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &cube_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, cube_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/cube/height.png",             cube_HEIGHT);         
      loadTexture("_MODEL_FOLDERS_/cube/cube_DOT3.bmp",          cube_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/cube/cube.png",               cube_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "cube.cpp"                                                                                                                
      glGenBuffers(1,              &cube_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, cube_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //--------------------------------------------------------------------------------------------------------------------     
      #include    "cube_INDEX.cpp" 
      glGenBuffers(1, &cube_INDEX_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_INDEX_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_INDEX), cube_INDEX, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
      //=================================================================================================================================       




