     #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      facing_VIEW_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_facing_VIEW =                                                                                                        

      "    #define highp                                                                                        \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                            \n"                           
      "    uniform         mat4   mvpMatrix;                                                                    \n"                           
      "    uniform         mat4   mvMatrix;                                                                     \n"        
      "    uniform         mat4   lightMatrix;                                                                  \n"                           
     
      "    attribute       vec4   position;                                                                     \n"                           
      "    attribute       vec3   normal;                                                                       \n"         
      "    attribute       vec3   tangent;                                                                      \n"             
      "    attribute       vec2   texture;                                                                      \n"                           

      "    varying highp   vec4   lightPosition_PASS;                                                           \n"                           
      "    varying highp   vec3   lightDirection;                                                               \n"        
      "    varying highp   vec3   EyeDir;                                                                       \n"  
      "    uniform highp float   shininess;                                                                                                        \n"                       
           
      "    varying highp   vec3   column0;                                                                      \n"   
      "    varying highp   vec3   column1;                                                                      \n"   
      "    varying highp   vec3   column2;                                                                      \n"        
      
      "    varying highp   vec2   varTexcoord;                                                                \n"                           

      "    vec3 view;                                                                                           \n"    

      "    void main()                                                                                          \n"                           
      "    {                                                                                                    \n"                           

        "        column0               =  -(mvMatrix[0].xyz).xyz;                                                 \n"
      "        column1               =  -(mvMatrix[1].xyz).xyz;                                                 \n"
      "        column2               =  -(mvMatrix[2].xyz).xyz;                                                 \n"
      
      "        vec3 n                = (mvMatrix * vec4(normal, 0.0)).xyz;                                          \n"
      "        vec3 t                = (mvMatrix * vec4(tangent, 0.0)).xyz;                                         \n"
      "        vec3 b                =  normalize( cross(n, t));                                                \n"  
      
      "        vec3 pos         =  (mvMatrix * position).xyz;                                              \n"
     
      "        vec3 dirEye           =  pos;                                                     \n"  
      
      "        EyeDir.x              =  dot(t.xyz , dirEye);                                                    \n"  
      "        EyeDir.y              =  dot(b.xyz , dirEye);                                                    \n"  
      "        EyeDir.z              =  dot(n.xyz , dirEye);                                                    \n"  
     //-----------------------------------------------------------------------------------------------------------------
      "        lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                             \n"                           

      "        varTexcoord           =  texture;                                                                \n"                           

      "        gl_Position           =  mvpMatrix * position;                                                   \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      facing_VIEW_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(facing_VIEW_SHADER_VERTEX, 1, &vertexSource_facing_VIEW, NULL);                                                                        
      glCompileShader(facing_VIEW_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_facing_VIEW =                                                                                                            

      " #ifdef GL_ES                                                                                                                               \n"                       
      " #else                                                                                                                                      \n"                       
      " #define highp                                                                                                                              \n"                       
      " #endif                                                                                                                                     \n"                       

      "    uniform sampler2D     Texture1;                                                                                                         \n"                       
      "    uniform sampler2D     NormalMap;                                                                                                        \n"                       
      "    uniform sampler2D     HeightMap;                                                                                                        \n"        
      "    uniform highp float   shininess;                                                                                                        \n"                       
      "    uniform highp vec4    light_POSITION_01;                                                                                                \n"    
      "    varying highp vec4    lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec3    lightDirection;                                                                                                   \n"      
      "    varying highp vec3    EyeDir;                                                                                                           \n"  
      "    varying highp vec3    column0;                                                                                                          \n"   
      "    varying highp vec3    column1;                                                                                                          \n"   
      "    varying highp vec3    column2;                                                                                                          \n"  
            
      "    varying highp vec2    varTexcoord;                                                                                                      \n"                       

      "            highp float   NdotL1;                                                                                                           \n"                       
      "            highp vec3    normal;                                                                                                           \n"                       
      "            highp vec3    NormalTex;                                                                                                        \n"                       


      " vec2 RayCast(sampler2D HMap, vec2 tc, vec3 ray);                                                                                           \n"  


      "     void main()                                                                                                                            \n"                       
      "     {                                                                                                                                      \n"                       

      "         vec2 TexCoords = RayCast(HeightMap, varTexcoord.xy, EyeDir);                                                                            \n"      
      //------------------------------------------------------------------------------------------------------------------------
      "         mat3 n = mat3(column0, column1, column2);                                                                                          \n"       
      
      "         NormalTex                  =  texture2D(NormalMap,  TexCoords.xy).xyz;                                                                \n"                       
      "         NormalTex                  = (NormalTex - 0.5);                                                                                    \n"                       
      "         normal                     =  normalize(NormalTex.xyz);                                                                            \n"
      "         NdotL1                     =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                                       \n"   
      //------------------------------------------------------------------------------------------------------------------------      
      
      "         gl_FragColor          =  vec4(1.0, 1.0, 1.0, 1.0) * NdotL1  * .0                                                                   \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) *NdotL1*NdotL1 * 1.0                                                           \n"                       

      "                               +  texture2D(Texture1, TexCoords.xy) * pow(NdotL1, 50.0) * vec4(2.0, 1.0, .1, 1.0)*0.5;                      \n"                       

      "    }                                                                                                                                       \n"   
      
"   vec2 RayCast(sampler2D HMap, vec2 tc, vec3 ray)                                                                                               \n"  
"   {                                                                                                                                             \n"  
"       int numsteps = 10;                                                                                                                        \n"  
"       int substeps = 5;                                                                                               \n"  
    
"       float height = 1.0;                                                                                               \n"  
"       float step= 1.0/float(numsteps);                                                                                               \n"  
"       int currStep;                                                                                               \n"  
"       vec4 tHeight= texture2D(HMap,tc);                                                                                               \n"  
"       vec2 delta = vec2( ray.x, ray.y) * 0.2 / -ray.z;// <-  add this to increase depth at sharp angles, this also causes increased error when model moves off center                                                                                         \n"  
//"       vec2 delta = vec2( ray.x, ray.y) * 0.04;                                                                        \n"  


    
"       for(int i=1; i<=numsteps;i++)                                                                                               \n"  
"       {                                                                                                                           \n"  
"           if(tHeight.x <= height)                                                                                                   \n"   
"           {                                                                                               \n"  
"               height -=step;                                                                                                \n"  
            //height = 1.0 - step*(i);                                                                                               \n"  
"               currStep=i;                                                                                               \n"  
"               tHeight= texture2D(HMap, tc - delta * height);                                                                                               \n"  
"           }                                                                                               \n"  
"       }                                                                                               \n"  

"       currStep-=1;                                                                                               \n"  
"       height +=step;                                                                                                \n"  

"       for(int i=0; i<substeps;i++)                                                                                               \n"  
"       {                                                                                                    \n"  
"           step*=0.5;                                                                                                       \n"  
"           height -=step;                                                                                                \n"  
"           tHeight= texture2D(HMap,tc - delta * height);                                                                                                \n"  
    
"           if(tHeight.x >= height)                                                                                               \n"
"           {                                                                                                  \n"
"               height+=step;                                                                                                       \n"      
"           }                                                                                               \n"
"       }                                                                                               \n"

"      return tc-delta*height;                                                                                                   \n"

"    }\n";
      
      
      
                                                                                                                                    



      //---------------------------------------------------------------------                                                                         
      facing_VIEW_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(facing_VIEW_SHADER_FRAGMENT, 1, &fragmentSource_facing_VIEW, NULL);                                                                          
      glCompileShader(facing_VIEW_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(facing_VIEW_SHADER, facing_VIEW_SHADER_VERTEX);                                                                                              
      glAttachShader(facing_VIEW_SHADER, facing_VIEW_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(facing_VIEW_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(facing_VIEW_SHADER, 1, "normal");       
      glBindAttribLocation(facing_VIEW_SHADER, 2, "tangent");         
      glBindAttribLocation(facing_VIEW_SHADER, 3, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(facing_VIEW_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(facing_VIEW_SHADER, facing_VIEW_SHADER_VERTEX);                                                                                              
      glDetachShader(facing_VIEW_SHADER, facing_VIEW_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(facing_VIEW_SHADER_VERTEX);                                                                                                            
      glDeleteShader(facing_VIEW_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_facing_VIEW                   = glGetUniformLocation(facing_VIEW_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_facing_VIEW                       = glGetUniformLocation(facing_VIEW_SHADER,   "mvMatrix");        
      UNIFORM_LIGHT_MATRIX_facing_VIEW                    = glGetUniformLocation(facing_VIEW_SHADER,   "lightMatrix");
      UNIFORM_LIGHT_POSITION_01_facing_VIEW               = glGetUniformLocation(facing_VIEW_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_facing_VIEW                       = glGetUniformLocation(facing_VIEW_SHADER,   "shininess");                                              
      UNIFORM_TEXTURE_HEIGHT_facing_VIEW                  = glGetUniformLocation(facing_VIEW_SHADER,   "HeightMap");                                                      
      UNIFORM_TEXTURE_DOT3_facing_VIEW                    = glGetUniformLocation(facing_VIEW_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_facing_VIEW                         = glGetUniformLocation(facing_VIEW_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"facing_VIEW_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &facing_VIEW_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, facing_VIEW_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"facing_VIEW" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &facing_VIEW_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, facing_VIEW_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/facing_VIEW/height.png",             facing_VIEW_HEIGHT);         
      loadTexture("_MODEL_FOLDERS_/facing_VIEW/facing_VIEW_DOT3.bmp",          facing_VIEW_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/facing_VIEW/facing_VIEW.png",               facing_VIEW_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "facing_VIEW.cpp"                                                                                                                
      glGenBuffers(1,              &facing_VIEW_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, facing_VIEW_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(facing_VIEW), facing_VIEW, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //--------------------------------------------------------------------------------------------------------------------     
      #include    "facing_VIEW_INDICES.cpp" 
      glGenBuffers(1, &facing_VIEW_INDICES_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facing_VIEW_INDICES_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(facing_VIEW_INDICES), facing_VIEW_INDICES, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
      //=================================================================================================================================       




