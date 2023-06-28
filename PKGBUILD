# Pkg build that runs cmake
# Maintainer: João Vieira 
# Contributors: Carlos Tojal
_pkgname=lart_common
pkgname=lib$_pkgname
pkgver=0.0.1
pkgrel=1
pkgdesc='Common library for the LART pipeline'
url='https://github.com/FSIPLEIRIA/lart_common'
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/v$pkgver.tar.gz")
arch=('x86_64')
depends=('git' 'cgal')
sha256sums=('5caafb3cd30e4f0245d67bdd4f88c153ee291e2661eec9d9a1b498028434e829')

build () {
  cd "$srcdir/$_pkgname-$pkgver"
  cmake -B build -S .

}

package() {
  cd "$srcdir/$_pkgname-$pkgver"
  make -C build DESTDIR="$pkgdir" install
}
