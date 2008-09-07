#include "scene.hh"

Camera::Camera(Point origin_, Vector3 direction_, Vector3 angle_,
               size_t width, size_t height, double ratio_, double fov_)
: origin(origin_), direction(direction_), angle(angle_), w(width), h(height),
  ratio(ratio_), fov(fov_)
{
	// TODO implement direction & angle
	direction = Vector3(1, 0, 0);
	double d = w * 1.0 / (ratio * 2 * tan(fov / 2) * M_PI / 180.0);
	double ww = w * 1.0 / ratio;
	double hh = h * 1.0 / ratio;

	Point s = {d, ww, hh};
	start = s;
	x = Vector3(0, 1, 0);
	y = Vector3(0, 0, -1);
}

Ray *Camera::shoot_ray(size_t i, size_t j)
{
	if (i >= w || j >= h) {
		throw std::out_of_range("index out of bounds");
	}

	Point p = start;
	p.x += i * x.get_x() / ratio;
	p.y += i * x.get_y() / ratio;
	p.z += i * x.get_z() / ratio;
	p.x += j * y.get_x() / ratio;
	p.y += j * y.get_y() / ratio;
	p.z += j * y.get_z() / ratio;

	ray_v = Vector3(origin, p);
	ray.direction = &ray_v;
	ray.origin = origin;
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
			double min_dist = std::numeric_limits<double>::infinity();
			const Primitive *nearest = NULL;

			// find nearest object
			std::vector<const Primitive *>::const_iterator it;
			for (it = objects.begin(); it != objects.end(); ++it) {
				Point p = {0, 0, 0};
				if ((*it)->intersects(*ray, p)) {
					Vector3 v(ray->origin, p);
					double dist = v.length();
					if (dist < min_dist) {
						min_dist = dist;
						nearest = *it;
					}
				}
			}

			if (!nearest) {
				image.at(j).at(i) = bgcolor;
				continue;
			}
			
			// TODO remove
			image.at(j).at(i) = nearest->get_material().get_color();

			// check shadow
			// check reflection
			// check refraction
			// check distance and shading
			std::vector<const Light *>::const_iterator itt;
			for (itt = lights.begin(); itt != lights.end(); ++itt) {

			}

		}
	}
}

const ImageData& Scene::get_imagedata() const
{
	return image;
}
