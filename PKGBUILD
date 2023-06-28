# Pkg build that runs cmake
# Maintainer: João Vieira 
# Contributors: Carlos Tojal, João Vieira
_pkgname=pure_pursuit_core
pkgname=lib$_pkgname
pkgver=0.0.0_alpha
pkgrel=1
pkgdesc='A library intended to describe a trajectory for the lart pipeline'
url='https://github.com/FSIPLEIRIA/pure_pursuit_core'
source=("$pkgname-${pkgver//_/-}.tar.gz::$url/archive/refs/tags/v${pkgver//_/-}.tar.gz")
arch=('x86_64')
depends=('git' 'liblart_common')
sha256sums=('aa3eebbdd6b007656c03b5922151b8ba8271e64b757a29631fbe1f658cfb30ee')

build () {
  cd "$srcdir/$_pkgname-${pkgver//_/-}"
  cmake -B build -S .

}

package() {
  cd "$srcdir/$_pkgname-${pkgver//_/-}"
  make -C build DESTDIR="$pkgdir" install
}
