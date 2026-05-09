add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"}) -- generate compile commands

add_languages("c99")
if is_plat("linux") then
	set_policy("build.sanitizer.address", true)
	set_policy("build.sanitizer.leak", true)
end

add_requires("ncursesw")

add_includedirs("include")

target("nexocore")
	set_kind("static")

	add_files("src/core/*.c")
	add_packages("ncursesw", {public=true})
target_end()

target("nexo")
	set_kind("binary")

	add_files("src/nexo/*.c")

	add_deps("nexocore")
target_end()

target("nexotest")
	set_kind("binary")
	set_default(false)

	add_files("src/tests/*.c")

	add_deps("nexocore")
target_end()
