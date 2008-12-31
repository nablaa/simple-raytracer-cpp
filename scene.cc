#include "scene.hh"

Camera::Camera(Point origin_, Matrix3 rotation_,
       size_t width, size_t height, double factor_)
: origin(origin_), rotation(rotation_), w(width), h(height), factor(factor_),
  dx(factor_ / width), dy(factor_ / height)
{
	rotation = rotation.transpose();
}

Ray *Camera::shoot_ray(size_t i, size_t j)
{
	if (i < 0 || j < 0 || i >= w || j >= h) {
		throw std::out_of_range("index out of bounds");
	}

	ray_v = rotation.col(3) + (-rotation.col(1)).mul(w / 2.0 * dx - i * dx) +
	        (-rotation.col(2)).mul(h / 2.0 * dy - j * dy);

	ray.origin = origin;
	ray.direction = &ray_v;
	ray.direction->normalize();

	return &ray;
}

size_t Camera::get_width() const
{
	return w;
}

size_t Camera::get_height() const
{
	return h;
}


Scene::Scene(Camera& camera_, Color bg_)
: camera(camera_), bgcolor(bg_)
{
	// initialize image
	image = ImageData(camera.get_height());
	for (size_t j = 0; j < camera.get_height(); ++j) {
		image.at(j) = std::vector<Color>(camera.get_width());
	}
}

void Scene::add_object(const Primitive *p)
{
	if (!p) {
		throw std::runtime_error("primitive NULL");
	}
	objects.push_back(p);
}

void Scene::add_light(const Light *l)
{
	if (!l) {
		throw std::runtime_error("light NULL");
	}
	lights.push_back(l);
}

void Scene::render()
{
	for (size_t j = 0; j < camera.get_height(); ++j) {
		for (size_t i = 0; i < camera.get_width(); ++i) {
			Ray *ray = camera.shoot_ray(i, j);
			ray->direction->normalize();
			double min_dist = std::numeric_limits<double>::infinity();
			const Primitive *nearest = NULL;

			// find nearest object
			Point nearest_p = {0, 0, 0};
			std::vector<const Primitive *>::const_iterator it;
			for (it = objects.begin(); it != objects.end(); ++it) {
				Point p = {0, 0, 0};
				if ((*it)->intersects(*ray, p)) {
					Vector3 v(ray->origin, p);
					double dist = v.length();
					if (dist < min_dist) {
						min_dist = dist;
						nearest = *it;
						nearest_p = p;
					}
				}
			}

			if (!nearest) {
				image.at(j).at(i) = bgcolor;
				continue;
			}

			// TODO primitive: get_normal()
			Vector3 normal(nearest->get_location(), nearest_p);
			normal.normalize();
			double error = 0.001;
			Point hit_p = { nearest_p.x + normal.get_x() * error,
			                nearest_p.y + normal.get_y() * error,
			                nearest_p.z + normal.get_z() * error };
			
			// TODO remove
			//image.at(j).at(i) = nearest->get_material().get_color();

			// check shadow
			// check reflection
			// check refraction
			// check distance and shading
			bool in_shadow = false;
			const Light *l = NULL;
			double l_dist = 0;
			std::vector<const Light *>::const_iterator itt;
			for (itt = lights.begin(); itt != lights.end(); ++itt) {
				l = *itt;
				Vector3 shadow_v(hit_p, (*itt)->origin);
				l_dist = shadow_v.length();
				Ray s_ray;
				shadow_v.normalize();
				s_ray.direction = &shadow_v;

				//std::cout << "p.x: " << p.x << "\thit_p.x: " << hit_p.x << std::endl;
				s_ray.origin = hit_p;
				std::vector<const Primitive *>::const_iterator jt;
				for (jt = objects.begin(); jt != objects.end(); ++jt) {
					Point temp;
					if ((*jt)->intersects(s_ray, temp)) {
						in_shadow = true;
					}
				}
				if (!in_shadow) {
					break;
				}
			}

			if (!l) {
				image.at(j).at(i) = nearest->get_material().get_color();
			} else {
				image.at(j).at(i) = calculate_shading(nearest->get_material(),
				                                      in_shadow,
								      l->intensity, l_dist,
				                                      NULL, NULL, 0);
			}
		}
	}
}

const ImageData& Scene::get_imagedata() const
{
	return image;
}

Color Scene::calculate_shading(const Material& mat, bool in_shadow,
                               double l_intensity, double l_distance,
                               const Color *refraction_color,
                               const Color *reflection_color, double rs)
{
	if (in_shadow) {
		Color c = { 0, 0, 0};
		return c;
	}

	Color c = { mat.get_color().r, mat.get_color().g, mat.get_color().b };
	// TODO replace 255.0 with light color
	double light_color = 255.0 / (l_distance * l_distance);
	c.r *= light_color * l_intensity;
	c.g *= light_color * l_intensity;
	c.b *= light_color * l_intensity;
	if (c.r > 1.0) {
		c.r = 1.0;
	}
	if (c.g > 1.0) {
		c.g = 1.0;
	}
	if (c.b > 1.0) {
		c.b = 1.0;
	}
	return c;
}
