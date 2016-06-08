#include "SolidSphere.h"




	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;
	std::vector<std::vector<GLfloat>> animationTextCoords;

	unsigned int TextureID;
	SolidSphere::SolidSphere(float radius, unsigned int rings, unsigned int sectors,char* path)
	{
		animated = false;
		TexturePath = path;
		float const R = 1. / (float)(rings - 1);
		float const S = 1. / (float)(sectors - 1);
		int r, s;

		vertices.resize(rings * sectors * 3);
		normals.resize(rings * sectors * 3);
		texcoords.resize(rings * sectors * 2);
		std::vector<GLfloat>::iterator v = vertices.begin();
		std::vector<GLfloat>::iterator n = normals.begin();
		std::vector<GLfloat>::iterator t = texcoords.begin();
		for (r = 0; r < rings; r++) for (s = 0; s < sectors; s++) {
			float const y = sin(-M_PI_2 + M_PI * r * R);
			float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
			float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

			*t++ = s*S;
			*t++ = r*R;

			*v++ = x * radius;
			*v++ = y * radius;
			*v++ = z * radius;

			*n++ = x;
			*n++ = y;
			*n++ = z;
		}

		indices.resize(rings * sectors * 4);
		std::vector<GLushort>::iterator i = indices.begin();
		for (r = 0; r < rings - 1; r++) for (s = 0; s < sectors - 1; s++) {
			*i++ = r * sectors + s;
			*i++ = r * sectors + (s + 1);
			*i++ = (r + 1) * sectors + (s + 1);
			*i++ = (r + 1) * sectors + s;
		}
		init();
	}

	SolidSphere::SolidSphere(float radius, unsigned int rings, unsigned int sectors, char * path, int texturesxy)
	{
		animated = true;
		TexturesGrid = texturesxy;
		
		TexturePath = path;
		float const R = 1. / (float)(rings - 1);
		float const S = 1. / (float)(sectors - 1);
		int r, s;
		animationTextCoords.resize(TexturesGrid*TexturesGrid);
		vertices.resize(rings * sectors * 3);
		normals.resize(rings * sectors * 3);
		texcoords.resize(rings * sectors * 2);
		std::vector<GLfloat>::iterator v = vertices.begin();
		std::vector<GLfloat>::iterator n = normals.begin();
		//std::vector<GLfloat>::iterator t = animationTextCoords.begin();
		for (r = 0; r < rings; r++) for (s = 0; s < sectors; s++) {
			float const y = sin(-M_PI_2 + M_PI * r * R);
			float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
			float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

			//*t++ = s*S/TexturesGrid;
			//*t++ = r*R/ TexturesGrid;
			for (int i = 0; i < TexturesGrid; i++)
			{
				for (int k = 0; k < TexturesGrid; k++)
				{
					animationTextCoords[((i)*TexturesGrid)+k].push_back(s*S / TexturesGrid * (k+1));
					animationTextCoords[((i)*TexturesGrid)+k].push_back(r*R / TexturesGrid * (i+1));
				}
			}

			*v++ = x * radius;
			*v++ = y * radius;
			*v++ = z * radius;

			*n++ = x;
			*n++ = y;
			*n++ = z;
		}

		indices.resize(rings * sectors * 4);
		std::vector<GLushort>::iterator i = indices.begin();
		for (r = 0; r < rings - 1; r++) for (s = 0; s < sectors - 1; s++) {
			*i++ = r * sectors + s;
			*i++ = r * sectors + (s + 1);
			*i++ = (r + 1) * sectors + (s + 1);
			*i++ = (r + 1) * sectors + s;
		}
		init();
	}

	void SolidSphere::draw(GLfloat x, GLfloat y, GLfloat z)
	{
		glPushMatrix();
		glTranslatef(x, y, z);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
		glNormalPointer(GL_FLOAT, 0, &normals[0]);
		glTexCoordPointer(2, GL_FLOAT, 0, &texcoords[0]);
		glDrawElements(GL_QUADS, indices.size(), GL_UNSIGNED_SHORT, &indices[0]);
		glPopMatrix();
	}

	void SolidSphere::init()
	{
		if (TextureID == NULL)
		{
			int width, height, bpp;
			glGenTextures(1, &TextureID);
			unsigned char* texture = stbi_load(TexturePath, &width, &height, &bpp, 4);
			glBindTexture(GL_TEXTURE_2D, TextureID);
			glTexImage2D(GL_TEXTURE_2D,
				0,		//level
				GL_RGBA,		//internal format
				width,		//width
				height,		//height
				0,		//border
				GL_RGBA,		//data format
				GL_UNSIGNED_BYTE,	//data type
				texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
		}
	}

